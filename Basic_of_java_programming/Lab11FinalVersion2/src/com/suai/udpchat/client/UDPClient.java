package com.suai.udpchat.client;

import java.io.IOException;
import java.net.*;

public class UDPClient {
    private final static int SERVICE_PORT = 9876;
    private final static int BUFFER_SIZE = 1024;
    public static void main(String[] args) {
        try {
            DatagramSocket clientSocket = new DatagramSocket();
            InetAddress IPAddress = InetAddress.getByName("localhost");

            byte[] sendingData = new byte[BUFFER_SIZE];
            byte[] receivingData = new byte[BUFFER_SIZE];

            String sentence = "Hello from UDP Client!";
            sendingData = sentence.getBytes();

            DatagramPacket outputPacket = new DatagramPacket(sendingData, sendingData.length,
                                                             IPAddress, SERVICE_PORT);
            clientSocket.send(outputPacket);

            DatagramPacket inputPacket = new DatagramPacket(receivingData, receivingData.length);
            clientSocket.receive(inputPacket);

            String receivedData = new String(inputPacket.getData(), 0, inputPacket.getLength());
            System.out.println("Message from UDPServer: " + receivedData);
            clientSocket.close();

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
