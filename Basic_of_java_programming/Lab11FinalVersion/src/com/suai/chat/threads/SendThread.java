package com.suai.chat.threads;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class SendThread extends Thread {
    private final InetAddress ipAddress;
    private final DatagramSocket sender;
    private final int port;

    public SendThread(DatagramSocket sender, InetAddress ipAddress, int port) {
        this.ipAddress = ipAddress;
        this.sender = sender;
        this.port = port;
    }

    @Override
    public void run() {
        String name = "Opponent";
        while (true) {
            BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
            String send;
            try {
                send = inFromUser.readLine();
                if(send.equals("@quit")) {
                    String endMessage = name + "has disconnected.";
                    DatagramPacket res = new DatagramPacket(endMessage.getBytes(), endMessage.getBytes().length,
                                                            ipAddress, port);
                    try {
                        sender.send(res);
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                    sender.close();
                    System.exit(0);
                }

                String[] splitSend = send.split(" ");
                if(splitSend[0].equals("@name")) {
                    name = splitSend[1];
                    System.out.println("Your name has successfully changed!");
                    continue;
                }
                StringBuilder message = new StringBuilder();
                message.append(name).append(": ").append(send);
                try {
                    DatagramPacket output = new DatagramPacket(message.toString().getBytes(),
                                                               message.toString().getBytes().length,
                                                               ipAddress, port);
                    sender.send(output);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
