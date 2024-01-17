import java.io.File;

public class RenameImages {

    public static void main(String[] args) {
        // Укажите путь к папке с изображениями
        String folderPath = "D:\\Studies\\ML\\Lab2\\Pictures_numbers";

        // Проверка существования папки
        File folder = new File(folderPath);
        if (!folder.exists() || !folder.isDirectory()) {
            System.out.println("Not found directory.");
            return;
        }

        // Получение списка файлов в папке
        File[] files = folder.listFiles();

        if (files != null) {
            // Переименование файлов
            for (int i = 0; i < files.length; i++) {
                String fileName = (i + 1) + ".png";
                File newFile = new File(folderPath, fileName);

                if (files[i].renameTo(newFile)) {
                    System.out.println("File " + files[i].getName() + " sucsess rename в " + fileName);
                } else {
                    System.out.println("Can't rename " + files[i].getName());
                }
            }
        } else {
            System.out.println("Empry direcotry.");
        }
    }
}