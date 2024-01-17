package com.chat.client;

import static com.chat.utils.ConnectionUtils.HOST_NAME;
import static com.chat.utils.ConnectionUtils.PORT;
import static com.chat.utils.ConnectionUtils.decryptMessage;
import static com.chat.utils.ConnectionUtils.encryptMessage;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class Client implements Runnable {
    private Socket clientSocket;
    private BufferedReader in;
    private PrintWriter out;
    private boolean done;
    private String tgt;
    private final Map<String, String> secretKeyDB;
    private String nickname;

    public Client() {
        done = false;
        secretKeyDB = new HashMap<>();
        secretKeyDB.put("Alice", "DcjAtQDoAesk8Mlppg/f2w==");
        secretKeyDB.put("Bob", "Qdbe+PYMSo5I3JFl9KZcGw==");
    }

    @Override
    public void run() {
        try {
            clientSocket = new Socket(HOST_NAME, PORT);
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            InputHandler inputHandler = new InputHandler();
            Thread t = new Thread(inputHandler);
            t.start();

            String inMessage;
            while ((inMessage = in.readLine()) != null) {
                if (inMessage.startsWith("/tgt")) {
                    String[] messageSplit = inMessage.split(" ", 2);

                    String encryptedTgt = messageSplit[1];
                    tgt = decryptMessage(secretKeyDB.get(nickname), encryptedTgt);

                    System.out.println("Encrypted session key: " + messageSplit[1]);
                    System.out.println("Decrypted session key: " + tgt);
                } else if (inMessage.startsWith("/nickname")) {
                    String[] messageSplit = inMessage.split(" ", 2);
                    nickname = messageSplit[1];
                } else if (inMessage.startsWith("/message")) {
                    String[] messageSplit = inMessage.split(" ", 3);
                    String senderName = messageSplit[1];
                    String encryptedMessage = messageSplit[2];
                    String decryptedMessage = decryptMessage(tgt, encryptedMessage);
                    System.out.println(senderName + " " + decryptedMessage);
                } else if (inMessage.startsWith("/hello")) {
                    String[] messageSplit = inMessage.split(" ", 2);
                    System.out.println(messageSplit[1]);
                } else if (inMessage.startsWith("/info")) {
                    System.out.println(inMessage.substring(5));
                } else {
                    System.out.println(inMessage);
                }
            }
        } catch (Exception e) {
            shutdown();
        }
    }

    public void shutdown() {
        done = true;
        try {
            in.close();
            out.close();
            if (!clientSocket.isClosed()) {
                clientSocket.close();
            }
        } catch (IOException e) {
            //ignore
        }
    }

    class InputHandler implements Runnable {
        @Override
        public void run() {
            BufferedReader inReader = new BufferedReader(new InputStreamReader(System.in));
            while (!done) {
                try {
                    String message = inReader.readLine();
                    if (message.startsWith("/tgt")) {
                        out.println(message);
                    } else if (message.startsWith("/quite")) {
                        out.println(message);
                        inReader.close();
                        shutdown();
                    } else if (message.startsWith("/message")) {
                        String[] messageSplit = message.split(" ", 3);
                        String command = messageSplit[0];
                        String recipientName = messageSplit[1];
                        String encryptedMessage = encryptMessage(tgt, messageSplit[2]);

                        String encryptedSessionKey = encryptMessage(secretKeyDB.get(nickname), tgt);
                        System.out.println("Encrypted message: " + encryptedMessage);

                        //Send session key for recipient
                        out.println("/sessionKey " + encryptedSessionKey + " " + recipientName);

                        //Send encrypted message
                        out.println(command + " " + recipientName + " " + encryptedMessage);
                    } else {
                        out.println(message);
                    }
                } catch (Exception e) {
                    shutdown();
                }
            }
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.run();
    }
}
