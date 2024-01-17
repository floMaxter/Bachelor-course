package com.suai.chat.server;

import com.suai.chat.Utilities;
import com.suai.chat.threads.ReceiveThread;
import com.suai.chat.threads.SendThread;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

import static com.suai.chat.Utilities.DEFAULT_PORT;
import static com.suai.chat.Utilities.PACKET_SIZE;

public class UDPServer {
    private final DatagramSocket datagramSocket;
    private final byte[] buffer;

    public UDPServer(String[] args) throws SocketException {
        this.buffer = new byte[PACKET_SIZE];
        if(args == null || args.length != 2) {
            datagramSocket = new DatagramSocket(DEFAULT_PORT);
        } else {
            datagramSocket = new DatagramSocket(Integer.parseInt(args[1]));
        }
    }

    public void receiveThenSend() throws IOException {
        DatagramPacket datagramPacket = new DatagramPacket(buffer, buffer.length);
        System.out.println("Server wait...");
        datagramSocket.receive(datagramPacket);

        InetAddress inetAddress = datagramPacket.getAddress();
        int port = datagramPacket.getPort();

        ReceiveThread input = new ReceiveThread(datagramSocket);
        SendThread output = new SendThread(new DatagramSocket(), inetAddress, port);

        input.start();
        output.start();
        System.out.println("Client has joined the chat!");

        Utilities.welcomeFunction();
    }

    public static void main(String[] args) {
        UDPServer server = null;
        try {
            server = new UDPServer(args);
            System.out.println("Server started working.");
        } catch (SocketException e) {
            e.printStackTrace();
        }
        try {
            server.receiveThenSend();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
