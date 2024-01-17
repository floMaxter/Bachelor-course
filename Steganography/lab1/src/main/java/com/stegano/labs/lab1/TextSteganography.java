package com.stegano.labs.lab1;

import static com.stegano.labs.lab1.UtilsLab1.BIT_DEPTH;
import static com.stegano.labs.lab1.UtilsLab1.END_SEQUENCE;
import static com.stegano.labs.lab1.UtilsLab1.INSERT_CHAR;

public class TextSteganography {

    public static String embedText(String embedText, String target) {
        String binEmbedText = toBinaryString(embedText);
        System.out.println("Встроенные биты: " + binEmbedText);
        System.out.println("Количество встроенных бит: " + binEmbedText.length());

        StringBuilder resContainer = new StringBuilder();
        int j = 0;
        for (int i = 0; i < target.length(); i++) {
            while (i < target.length() && target.charAt(i) != ' ') {
                resContainer.append(target.charAt(i));
                i++;
            }
            if (i < target.length()) {
                if (j < binEmbedText.length() && binEmbedText.charAt(j) == '1') {
                    resContainer.append(INSERT_CHAR);
                } else if (j >= binEmbedText.length()) {
                    resContainer.append(END_SEQUENCE);
                    resContainer.append(target.substring(i + 1));
                    break;
                } else {
                    resContainer.append(target.charAt(i));
                }
                j++;
            }
        }

        return resContainer.toString();
    }

    public static String extractText(String container) {
        String binEmbedText = extractBinaryEmbedText(container);
        System.out.println("Извлекаемые биты: " + binEmbedText);
        System.out.println("Количество извлекаемых бит: " + binEmbedText.length());
        return toCharacterString(binEmbedText);
    }

    public static String clearContainer(String containerText) {
        return containerText.replace('*', ' ');
    }

    private static String toBinaryString(String text) {
        StringBuilder binaryString = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            binaryString.append(String.format("%" + BIT_DEPTH + "s",
                    Integer.toBinaryString(text.charAt(i))).replace(' ', '0'));
        }
        return binaryString.toString();
    }

    private static String toCharacterString(String binText) {
        String splitBinText = splitIntoSymbol(binText);
        String[] binArray = splitBinText.split(" ");
        StringBuilder text = new StringBuilder();
        for (String binChar : binArray) {
            int charValue = Integer.parseInt(binChar, 2);
            char currChar = (char) charValue;
            text.append(currChar);
        }
        return text.toString();
    }

    private static String splitIntoSymbol(String binText) {
        int chunkSize = BIT_DEPTH;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < binText.length(); i += chunkSize) {
            int endIndex = Math.min(i + chunkSize, binText.length());
            String chunk = binText.substring(i, endIndex);
            res.append(chunk).append(" ");
        }
        return res.toString();
    }

    private static String extractBinaryEmbedText(String target) {
        StringBuilder binEmbedText = new StringBuilder();
        for (int i = 0; i < target.length(); i++) {
            if (target.charAt(i) == ' ') {
                binEmbedText.append('0');
            } else if (target.charAt(i) == INSERT_CHAR) {
                if (i + 1 < target.length()) {
                    if (target.charAt(i + 1) == INSERT_CHAR) {
                        break;
                    }
                }
                binEmbedText.append('1');
            }
        }
        return binEmbedText.toString();
    }
}
