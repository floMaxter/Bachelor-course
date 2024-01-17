package com.suai.chat.client;

import com.suai.chat.Utilities;
import com.suai.chat.threads.ReceiveThread;
import com.suai.chat.threads.SendThread;

import java.io.IOException;
import java.net.*;

import static com.suai.chat.Utilities.*;
import static com.suai.chat.Utilities.DEFAULT_PORT;
import static com.suai.chat.Utilities.PACKET_SIZE;

public class UDPClient {
    private final DatagramSocket datagramSocket;
    private final InetAddress inetAddress;
    private final int port;
    private final byte[] buffer;

    public UDPClient(String[] args) throws SocketException, UnknownHostException {
        this.datagramSocket = new DatagramSocket();
        buffer = new byte[PACKET_SIZE];
        if(args == null || args.length != 2) {
            this.inetAddress = InetAddress.getByName(DEFAULT_IP);
            this.port = DEFAULT_PORT;
        } else {
            this.inetAddress = InetAddress.getByName(args[0]);
            this.port = Integer.parseInt(args[1]);
        }
    }

    public void sendThenReceive() throws InterruptedException, IOException {
        DatagramPacket datagramPacket = new DatagramPacket(buffer, buffer.length, inetAddress, port);
        datagramSocket.send(datagramPacket);

        SendThread output = new SendThread(this.datagramSocket, this.inetAddress, this.port);
        ReceiveThread input = new ReceiveThread(this.datagramSocket);

        output.start();
        input.start();

        System.out.println("You have joined the chat!");
        Utilities.welcomeFunction();
        output.join();
    }

    public static void main(String[] args) {
        UDPClient client = null;
        try {
            client = new UDPClient(args);
            System.out.println("Client started working.");
        } catch (SocketException | UnknownHostException e) {
            e.printStackTrace();
        }
        try {
            client.sendThenReceive();
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }
}
