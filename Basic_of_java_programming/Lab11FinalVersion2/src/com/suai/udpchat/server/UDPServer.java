package com.suai.udpchat.server;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer {
    private final static int SERVICE_PORT = 9876;
    private final static int BUFFER_SIZE = 1024;
    public static void main(String[] args) {
        try {
            DatagramSocket serverSocket = new DatagramSocket(SERVICE_PORT);
            byte[] receivingData = new byte[BUFFER_SIZE];
            byte[] sendingData = new byte[BUFFER_SIZE];

            DatagramPacket inputPacket = new DatagramPacket(receivingData, receivingData.length);
            System.out.println("Waiting for a client to connected...");

            serverSocket.receive(inputPacket);
            String receivedData = new String(inputPacket.getData(), 0, inputPacket.getLength());
            System.out.println("Message from UDPClient: " + receivedData);

            sendingData = receivedData.toUpperCase().getBytes();
            InetAddress senderAddress = inputPacket.getAddress();
            int senderPort = inputPacket.getPort();

            DatagramPacket outputPacket = new DatagramPacket(sendingData, sendingData.length,
                                                             senderAddress, senderPort);
            serverSocket.send(outputPacket);
            serverSocket.close();
        }  catch (IOException e) {
            e.printStackTrace();
        }
    }
}
