package com.chat.server;

import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.NoSuchAlgorithmException;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import static com.chat.utils.ConnectionUtils.*;


public class Server implements Runnable {
    private final List<ConnectionHandler> connections;
    private ServerSocket serverSocket;
    private boolean done;
    private ExecutorService pool;

    public Server() {
        connections = new ArrayList<>();
        done = false;
    }

    @Override
    public void run() {
        System.out.println("Server is start!");
        try {
            serverSocket = new ServerSocket(PORT);
            pool = Executors.newCachedThreadPool();
            while (!done) {
                Socket client = serverSocket.accept();
                ConnectionHandler handler = new ConnectionHandler(client);
                connections.add(handler);
                pool.execute(handler);
            }
        } catch (Exception e) {
            shutdown();
        }
    }

    public void broadcast(String message) {
        for (ConnectionHandler ch : connections) {
            if (ch != null && ch.isAuthenticated) {
                ch.sendMessage(message);
            }
        }
    }

    public boolean broadcast(String message, String nickname) {
        boolean isSend = false;
        for (ConnectionHandler ch : connections) {
            if (ch != null && ch.nickname.equals(nickname)) {
                ch.sendMessage(message);
                isSend = true;
            }
        }
        return isSend;
    }

    public void shutdown() {
        try {
            done = true;
            pool.shutdown();
            if (!serverSocket.isClosed()) {
                serverSocket.close();
            }
            for (ConnectionHandler ch : connections) {
                ch.shutdown();
            }
        } catch (IOException e) {
            //ignore or handler
            System.out.println("Server is shutdown!");
        }
    }

    class ConnectionHandler implements Runnable {
        private final Socket client;
        private BufferedReader in;
        private PrintWriter out;
        private String nickname;
        private boolean isAuthenticated;
        private final Map<String, String> secretKeyDB;
        public ConnectionHandler(Socket client) {
            this.client = client;
            this.isAuthenticated = false;
            secretKeyDB = new HashMap<>();
            secretKeyDB.put("Alice", "DcjAtQDoAesk8Mlppg/f2w==");
            secretKeyDB.put("Bob", "Qdbe+PYMSo5I3JFl9KZcGw==");
        }

        @Override
        public void run() {
            try {
                out = new PrintWriter(client.getOutputStream(), true);
                in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                out.println("/hello Please enter a nickname: ");
                nickname = in.readLine();
                out.println("/nickname " + nickname);

                System.out.println(nickname + " connected!");

                out.println("/info" +
                            "/nick - change the nickname " +
                            "/tgt - authentication " +
                            "/quit - left the chat " +
                            "/message + recipient's name + message - send a message to the user ");

                String message;
                while ((message = in.readLine()) != null) {
                    if (message.startsWith("/nick ")) {
                        String[] messageSplit = message.split(" ", 2);
                        if (messageSplit.length == 2) {
                            if (this.isAuthenticated) {
                                broadcast(nickname + " renamed themselves to " + messageSplit[1]);
                            }
                            System.out.println(nickname + " renamed themselves to " + messageSplit[1]);
                            nickname = messageSplit[1];
                            out.println("Successfully changed nickname to " + nickname);
                        } else {
                            out.println("No nickname provided!");
                        }
                    } else if (message.startsWith("/quit")) {
                        broadcast(nickname + " left the chat!");
                        shutdown();
                    } else if (message.startsWith("/tgt")) {
                        String sessionKey = generateSessionKey();

                        String encryptedSessionKey = encryptMessage(secretKeyDB.get(nickname), sessionKey);
                        out.println("/tgt " + encryptedSessionKey);
                        System.out.println("Generated session key: " + sessionKey);
                        System.out.println("Session key was encrypted: " + encryptedSessionKey);
                        System.out.println("The encrypted session key has been sent to " + nickname);

                        this.isAuthenticated = true;
                        System.out.println(nickname + " is authenticated");
                    } else if (message.startsWith("/sessionKey")) {
                        String[] messageSplit = message.split(" ", 3);
                        String sessionKey = messageSplit[1];
                        String recipientName = messageSplit[2];

                        //Decrypted session key from sender
                        String decryptedSessionKeySender = decryptMessage(secretKeyDB.get(nickname), sessionKey);

                        //Encrypted session key for recipient
                        String encryptedSessionKey =
                                encryptMessage(secretKeyDB.get(recipientName), decryptedSessionKeySender);
                        boolean isSend = broadcast("/tgt " + encryptedSessionKey, recipientName);
                        System.out.println("Received session key: " + sessionKey + " from " + nickname);
                        System.out.println("Session key was decrypted: " + decryptedSessionKeySender);
                        System.out.println("Session key was encrypted: " + encryptedSessionKey + " for " + recipientName);

                        if (isSend) {
                            System.out.println("The encrypted session key has been sent to " + recipientName);
                            out.println("The encrypted session key has been sent to " + recipientName);
                        } else {
                            System.out.println("The encrypted session key from " + nickname +
                                    "was not delivered to the " + recipientName);
                            out.println("The encrypted session key was not delivered to " + recipientName);
                        }
                    } else if (message.startsWith("/message")) {
                        if (isAuthenticated) {
                            String[] messageSplit = message.split(" ", 3);
                            String recipientName = messageSplit[1];
                            String messageToSend = messageSplit[2];

                            boolean isSend = broadcast("/message " + nickname + ": " + messageToSend, recipientName);
                            if (isSend) {
                                System.out.println(nickname + " sent a message to " + recipientName);
                                out.println("The message has been delivered");
                            } else {
                                System.out.println("The message from " + nickname +
                                        "was not delivered to the " + recipientName);
                                out.println("The message was not delivered to " + recipientName);
                            }
                        } else {
                            System.out.println("Alice is not authenticated, so she cannot send messages.");
                            out.println("Authenticate yourself using \"/tgt\" to send messages");
                        }
                    } else {
                        out.println("Unsupported action");
                    }
                }
            } catch (Exception e) {
                shutdown();
            }
        }

        public String generateSessionKey() {
            try {
                KeyGenerator keyGen = KeyGenerator.getInstance("AES");
                keyGen.init(128);
                SecretKey sessionKey = keyGen.generateKey();
                return Base64.getEncoder().encodeToString(sessionKey.getEncoded());
            } catch (NoSuchAlgorithmException e) {
                throw new RuntimeException(e);
            }
        }


        public void sendMessage(String message) {
            out.println(message);
        }

        public void shutdown() {
            try {
                in.close();
                out.close();
                if (!client.isClosed()) {
                    client.close();
                }
            } catch (IOException e) {
                //ignore
            }
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        server.run();
    }
}
