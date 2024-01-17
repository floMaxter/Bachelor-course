import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.Queue;

public class Tree {
    private TreeNode root;
    private int amountOfElements;

    public Tree() {
        root = null;
        amountOfElements = 0;
    }

    public int getAmount() {
        return this.amountOfElements;
    }

    public void insertNode(int value) {
        TreeNode node = new TreeNode();
        node.setValue(value);
        if (root == null) {
            root = node;
            amountOfElements++;
        } else {
            TreeNode currentNode = root;
            TreeNode parentNode;
            while (true) {
                parentNode = currentNode;
                if (value == currentNode.getValue()) {
                    return;
                } else if (value < currentNode.getValue()) {
                    currentNode = currentNode.getLeft();
                    if (currentNode == null) {
                        parentNode.setLeft(node);
                        amountOfElements++;
                        return;
                    }
                } else {
                    currentNode = currentNode.getRight();
                    if (currentNode == null) {
                        parentNode.setRight(node);
                        amountOfElements++;
                        return;
                    }
                }
            }
        }
    }

    private Path checkFileForLoad(String filename) throws IOException {
        Path file = Paths.get(filename);
        if (!Files.exists(file)) {
            throw new IOException("This file doesn't exist");
        }
        if (!Files.isReadable(file)) {
            throw new IOException("This file is open for writing only");
        }
        return file;
    }

    private void checkFileForSave(String filename) throws IOException {
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
    }

    private String BFS() {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        StringBuilder sb = new StringBuilder();

        while(!queue.isEmpty()) {
            TreeNode node = queue.remove();
            sb.append(node.getValue()).append(" ");

            if(node.getLeft() != null) {
                queue.add(node.getLeft());
            }
            if(node.getRight() != null) {
                queue.add(node.getRight());
            }
        }
        return sb.toString();
    }

    public void saveToTextFile(String filename) throws IOException {
        checkFileForSave(filename);

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filename))) {
            bw.write(BFS());
        }
    }

    public void loadFromTextFile(String filename) throws IOException {
        checkFileForLoad(filename);

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            if((line = br.readLine()) == null) {
                throw new IOException("File is empty!");
            }
            String[] split = line.split(" ");
            for (String s : split) {
                this.insertNode(Integer.parseInt(s));
            }
        }
    }

    public void saveToBinaryFile(String filename) throws IOException {
        checkFileForSave(filename);

        try (FileOutputStream fos = new FileOutputStream(filename);
             DataOutputStream dos = new DataOutputStream(fos)) {

            dos.writeInt(amountOfElements);

            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);

            while(!queue.isEmpty()) {
                TreeNode node = queue.remove();
                dos.writeInt(node.getValue());

                if(node.getLeft() != null) {
                    queue.add(node.getLeft());
                }
                if(node.getRight() != null) {
                    queue.add(node.getRight());
                }
            }
        }
    }

    public void loadFromBinaryFile(String filename) throws IOException {
        Path file = checkFileForLoad(filename);

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
                this.insertNode(value);
                i++;
            }
        }
    }

    @Override
    public String toString() {
        return root.toString();
    }
}
