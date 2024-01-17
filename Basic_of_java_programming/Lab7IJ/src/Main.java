import java.io.IOException;

public class Main {
    public static void testForTextFile() {
        String pathTextFile = "/home/max/Java/Code/Lab7IJ/TextFile.txt";
        Settings settings1 = new Settings();
        Settings settings2 = new Settings();
        settings1.put("brightness", 1);
        settings1.put("sound", 2);
        settings1.put("BackgroundNumber", 3);

        try {
            settings1.saveToTextFile(pathTextFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try {
            settings2.loadFromTextFile(pathTextFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        System.out.println(settings1);
    }

    public static void testForBinaryFile() {
        String pathBinaryFile = "/home/max/Java/Code/Lab7IJ/BinaryFile.txt";
        Settings settings1 = new Settings();
        Settings settings2 = new Settings();
        settings1.put("settings1", 10);
        settings1.put("settings2", 20);
        settings1.put("setting3", 30);

        try {
            settings1.saveToBinaryFile(pathBinaryFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try {
            settings2.loadFromBinaryFile(pathBinaryFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        System.out.println(settings2);
    }

    public static void testDopTextFile() {
        String pathTextFile = "/home/max/Java/Code/Lab7IJ/TextFileForBinaryTree.txt";
        Tree tree = new Tree();
        Tree tree2 = new Tree();

        tree.insertNode(6);
        tree.insertNode(8);
        tree.insertNode(5);
        tree.insertNode(8);
        tree.insertNode(2);
        tree.insertNode(9);
        tree.insertNode(7);
        tree.insertNode(4);
        tree.insertNode(10);
        tree.insertNode(3);
        tree.insertNode(1);


        try {
            tree.saveToTextFile(pathTextFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try {
            tree2.loadFromTextFile(pathTextFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        System.out.println(tree);
        System.out.println(tree2);
    }

    public static void testDopBinaryFile() {
        String pathBinaryFile = "/home/max/Java/Code/Lab7IJ/BinaryFileForBinaryTree.txt";
        Tree tree = new Tree();
        Tree tree2 = new Tree();

        tree.insertNode(6);
        tree.insertNode(8);
        tree.insertNode(5);
        tree.insertNode(8);
        tree.insertNode(2);
        tree.insertNode(9);
        tree.insertNode(7);
        tree.insertNode(4);
        tree.insertNode(10);
        tree.insertNode(3);
        tree.insertNode(1);

        try {
            tree.saveToBinaryFile(pathBinaryFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try {
            tree2.loadFromBinaryFile(pathBinaryFile);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        System.out.println(tree);
        System.out.println(tree2);
    }

    public static void main(String[] args) {
        //testForTextFile();
        //testForBinaryFile();
        //testDopTextFile();
        //testDopBinaryFile();
    }
}