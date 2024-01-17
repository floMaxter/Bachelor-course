package com.suai.chat;

public class Utilities {
    public static final int PACKET_SIZE = 1024;
    public static final int DEFAULT_PORT = 9876;
    public static final String DEFAULT_IP = "localhost";

    public static void welcomeFunction() {
        System.out.println("Задать имя пользователя: (@name Name), \n" +
                            "Послать сообщение: (Привет!), \n" +
                            "Выйти: (@quit)");
    }
}
