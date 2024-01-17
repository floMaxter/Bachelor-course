package com.stegano.labs.lab1;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static com.stegano.labs.lab1.UtilsLab1.ENCODING;

public class Lab1App {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("lab1/src/main/resources/lab1_name_files.txt"))) {
            List<String> nameFiles = readFilesNames(sc);
            String containerFileName = nameFiles.get(0);
            String embeddedFileName = nameFiles.get(1);
            String mergeContainerName = nameFiles.get(2);
            String extractedFileName = nameFiles.get(3);

            String embedText = readFile(embeddedFileName, ENCODING);
            System.out.println("Встраиваивый текст: " + embedText);

            String containerText = TextSteganography.clearContainer(readFile(containerFileName, ENCODING));
            writeFile(containerFileName, containerText, ENCODING);

            String mergeContainer = TextSteganography.embedText(embedText, containerText);
            writeFile(mergeContainerName, mergeContainer, ENCODING);

            String containerWithEmbed = readFile(mergeContainerName, ENCODING);
            String extractedText = TextSteganography.extractText(containerWithEmbed);
            writeFile(extractedFileName, extractedText, ENCODING);

            System.out.println("Извлеченный текст: " + extractedText);

            writeFileSize(nameFiles);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static List<String> readFilesNames(Scanner sc) {
        List<String> nameFiles = new ArrayList<>();
        while (sc.hasNext()) {
            nameFiles.add(sc.nextLine());
        }
        return nameFiles;
    }

    public static String readFile(String fileName, Charset encoding) {
        String content;
        try (Scanner sc = new Scanner(new File(fileName), String.valueOf(encoding))) {
            content = sc.useDelimiter("\\A").next();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return content;
    }

    public static void writeFile(String fileName, String text, Charset encoding) {
        try (FileWriter fw = new FileWriter(fileName, encoding, false)) {
            fw.write(text);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void writeFileSize(List<String> listFileNames) {
        for (String currName : listFileNames) {
            File file = new File(currName);
            if (file.exists()) {
                System.out.println("Length " + currName + "=" + file.length());
            } else {
                System.out.println("File not exist");
            }
        }
    }
}
