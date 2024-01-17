package com.stegano.labs.lab2;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.awt.image.IndexColorModel;
import java.io.File;
import java.io.IOException;

public class Lab2App {
    public static void main( String[] args ) {
        BufferedImage image = null;
        try {
            image = ImageIO.read(new File("lab2/src/main/resources/Car.bmp"));
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }

        ColorModel colorModel = image.getColorModel();
    }
}
