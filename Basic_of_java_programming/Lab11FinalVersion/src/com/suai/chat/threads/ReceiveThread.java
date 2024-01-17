package com.suai.chat.threads;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

import static com.suai.chat.Utilities.*;

public class ReceiveThread extends Thread {
    private final DatagramSocket receiver;

    public ReceiveThread(DatagramSocket receiver) {
        this.receiver = receiver;
    }

    @Override
    public void run() {
        try {
            while(true) {
                byte[] receiveData = new byte[PACKET_SIZE];
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                receiver.receive(receivePacket);
                String message = new String(receivePacket.getData(), 0, receivePacket.getLength());
                System.out.println(message);
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
