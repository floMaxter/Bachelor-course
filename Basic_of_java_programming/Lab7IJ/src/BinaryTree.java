import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class BinaryTree {
    TreeSet binaryTree;

    public BinaryTree() {
        this.binaryTree = new TreeSet<>();
    }

    public void putCollection(int[] arr) {
        binaryTree = new TreeSet<>(Collections.singleton(arr));
    }

    public void put(int value) {
        binaryTree.add(value);
    }

    public SortedSet get(int firstNode, int secondNode) {
        return binaryTree.subSet(firstNode, secondNode);
    }

    public void saveToTextFile(String filename) throws IOException {
        Path file = Paths.get(filename);
        if (!Files.exists(file)) {
            Files.createFile(file);
            if (!Files.exists(file)) {
                throw new IOException("Such a file doesn't exist and cannot be created");
            }
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filename))) {
            for (Object o : binaryTree) {
                bw.write(o + " ");
            }
        }
    }

    public void loadFromTextFile(String filename) throws IOException {
        Path file = Paths.get(filename);
        if(!Files.exists(file)) {
            throw new IOException("This file doesn't exist");
        }

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line = br.readLine();
            String[] split = line.split(" ");
            Collections.addAll(binaryTree, split);
        }
    }

    public void saveToBinaryFile(String filename) throws IOException {
        Path file = Paths.get(filename);
        if (!Files.exists(file)) {
            Files.createFile(file);
            if (!Files.exists(file)) {
                throw new IOException("Such a file doesn't exist and cannot be created");
            }
        }
        if (!Files.isWritable(file)) {
            throw new IOException("File is read-only");
        }

        try (FileOutputStream fos = new FileOutputStream(filename);
             DataOutputStream dos = new DataOutputStream(fos)) {
            dos.writeInt(binaryTree.size());



        }
    }

    public void loadFromBinaryFile(String filename) throws IOException {
        Path file = Paths.get(filename);
        if (!Files.exists(file)) {
            throw new IOException("This file doesn't exist");
        }

        //Path file = checkFile(filename);

        File fileForLength = file.toFile();
        if (fileForLength.length() == 0) {
            throw new IOException("This file is empty");
        }

        try (FileInputStream fis = new FileInputStream(filename);
             DataInputStream dis = new DataInputStream(fis)) {
            int size = dis.readInt();
            int i = 0;

            while (i < size) {
                int value = dis.readInt();
                binaryTree.add(value);
                i++;
            }
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        BinaryTree that = (BinaryTree) o;
        return binaryTree.equals(that.binaryTree);
    }

    @Override
    public int hashCode() {
        return Objects.hash(binaryTree);
    }

    @Override
    public String toString() {
        return "BinaryTree{" +
                "binaryTree=" + binaryTree +
                '}';
    }
}
