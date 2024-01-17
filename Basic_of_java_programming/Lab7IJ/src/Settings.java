import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class Settings {
    private final HashMap<String, Integer> settings;

    public Settings() {
        settings = new HashMap<>();
    }

    public void put(String parameter, int value) {
        settings.put(parameter, value);
    }

    public int get(String parameter) {
        return settings.get(parameter);
    }

    public int delete(String parameter) {
        return settings.remove(parameter);
    }


    private Path checkFileForLoad(String filename) throws IOException {
        Path file = Paths.get(filename);
        if (!Files.exists(file)) {
            throw new IOException("This file doesn't exist");
        }
        if(!Files.isReadable(file)) {
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

    public void saveToTextFile(String filename) throws IOException {
        checkFileForSave(filename);

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filename))) {
            for (Map.Entry<String, Integer> entry : settings.entrySet()) {
                bw.write(entry.getKey() + " " + entry.getValue() + '\n');
            }
        }
    }

    public void loadFromTextFile(String filename) throws IOException {
        checkFileForLoad(filename);

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] split = line.split(" ");
                settings.put(split[0], Integer.parseInt(split[1]));
            }
        }
    }

    public void saveToBinaryFile(String filename) throws IOException {
        checkFileForSave(filename);

        try (FileOutputStream fos = new FileOutputStream(filename);
             DataOutputStream dos = new DataOutputStream(fos)) {
            dos.writeInt(settings.size());

            for (Map.Entry<String, Integer> entry : settings.entrySet()) {
                dos.writeUTF(entry.getKey());
                dos.writeInt(entry.getValue());
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
                String key = dis.readUTF();
                int value = dis.readInt();
                settings.put(key, value);
                i++;
            }
        }
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Settings)) {
            return false;
        }
        if (this == o) return true;
        if (getClass() != o.getClass()) return false;
        Settings settings1 = (Settings) o;
        return Objects.equals(settings, settings1.settings);
    }

    @Override
    public int hashCode() {
        return Objects.hash(settings);
    }

    @Override
    public String toString() {
        return "Settings{" +
                "settings=" + settings +
                '}';
    }
}
