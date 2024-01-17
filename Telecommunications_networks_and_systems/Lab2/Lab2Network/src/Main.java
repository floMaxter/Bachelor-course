
import java.io.FileWriter;
import java.io.IOException;
import java.nio.DoubleBuffer;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        try {
            int e = 10;
            int n = 10;
            int t = 2;

//            dop1(false, e);
//            dop2(false, e, n);
//            dop31(false, e);
//            dop32(false, e, n);
//            dop4(false, e, t);
//            dop5(false, e, t);

            base();

//            clearAllFile();
        } catch (Exception e) {
            System.out.println("Error! " + e.getMessage());
        }


    }

    public static void dop1(boolean filling, int e) throws Exception {
        System.out.println("********************");
        System.out.println("Task 1");

        if (filling && e == 0) {
            e = readNumberExperiments();
            double p = readErrorProbability();
            theoreticalDop1(p);
            practiceDop1(e, p);
        } else if (!filling && e > 0) {
            for (double p = 0; p <= 0.9; p += 0.1) {
                theoreticalDop1(p);
                practiceDop1(e, p);
            }
        } else {
            throw new Exception("Incorrect parameters");
        }
        System.out.println("********************");
    }

    public static void theoreticalDop1(double p) {
        double res = (double) 1 / (1 - p);
        System.out.println("f(" + (float) p + ") = " + (float) res);
        writeToFile("theoreticalDop1.txt", (float) res, (float) p);
    }

    public static void practiceDop1(int n, double p) {
        int count = n;
        for (int i = 0; i < n; i++) {
            while (Math.random() <= p) {
                count++;
            }
        }
        double res = (double) count / n;
        System.out.println("Practice res = " + (float) res);
        writeToFile("practiceDop1.txt", (float) res, (float) p);
    }

    public static void dop2(boolean filling, int e, int n) throws Exception {
        System.out.println("********************");
        System.out.println("Task 2");

        if (filling && e == 0 && n == 0) {
            e = readNumberExperiments();
            n = readNumberOfResubmissions(e);
            double p = readErrorProbability();

            theoreticalDop2(p, n);
            practiceDop2(p, n, e);
        } else if (!filling && e > 0 && n > 0) {
            for (double p = 0; p <= 0.9; p += 0.1) {
                theoreticalDop2(p, n);
                practiceDop2(p, n, e);
            }
        } else {
            throw new Exception("Incorrect parameters");
        }
        System.out.println("********************");
    }

    public static void theoreticalDop2(double p, int n) {
        double res = (1 - Math.pow(p, n)) / (1 - p);
        System.out.println("f(" + (float) p + ") = " + (float) res);
        writeToFile("theoreticalDop2.txt", (float) res, (float) p);
    }

    public static void practiceDop2(double p, int n, int e) {
        int count = 0;
        for (int i = 0; i < e; i++) {
            for (int j = 0; j < n; j++) {
                double rand = Math.random();
                count++;
                if (rand > p) {
                    break;
                }
            }
        }
        double res = (double) count / e;
        System.out.println("Practice res = " + (float) res);
        writeToFile("practiceDop2.txt", (float) res, (float) p);
    }

    public static void dop31(boolean filling, int e) throws Exception {
        System.out.println("********************");
        System.out.println("Task 3_1");

        if (filling && e == 0) {
            e = readNumberExperiments();
            double p = readErrorProbability();
            double pO = readErrorProbability();

            theoreticalDop31(p, pO);
            practiceDop31(p, pO, e);
        } else if (!filling && e > 0) {
            for (double p = 0; p <= 0.9; p += 0.1) {
                for (double pO = 0; pO <= 0.9; pO += 0.1) {
                    theoreticalDop31(p, pO);
                    practiceDop31(p, pO, e);
                }
            }
        } else {
            throw new Exception("Incorrect parameters");
        }

        System.out.println("********************");
    }

    public static void theoreticalDop31(double p, double pO) {
        double res = (double) 1 / (1 - p) * (1 - pO);
        System.out.println("f(" + (float) p + ", " + (float) pO + ") = " + (float) res);
        writeToFile("theoreticalDop31.txt", (float) res, (float) p, (float) pO);
    }

    public static void practiceDop31(double p, double pO, int e) {
        int count = e;
        for (int i = 0; i < e; i++) {
            while (Math.random() <= p && Math.random() <= pO) {
                count++;
            }
        }
        double res = (double) count / e;
        System.out.println("Practice res = " + res);
        writeToFile("practiceDop31.txt", (float) res, (float) p, (float) pO);
    }

    public static void dop32(boolean filling, int e, int n) throws Exception {
        System.out.println("********************");
        System.out.println("Task 3_2");

        if (filling && e == 0 && n == 0) {
            e = readNumberExperiments();
            n = readNumberOfResubmissions(e);
            double p = readErrorProbability();
            double pO = readErrorProbability();

            theoreticalDop32(p, pO, n);
            practiceDop32(p, pO, n, e);
        } else if (!filling && e > 0 && n > 0) {
            for (double p = 0; p <= 0.9; p += 0.1) {
                for (double pO = 0; pO <= 0.9; pO += 0.1) {
                    theoreticalDop32(p, pO, n);
                    practiceDop32(p, pO, n, e);
                }
            }
        } else {
            throw new Exception("Incorrect parameters");
        }

        System.out.println("********************");
    }

    public static void theoreticalDop32(double p, double pO, int n) {
        double res = (1 - Math.pow((p + pO - p * pO), n)) / ((1 - p) * (1 - pO));
        System.out.println("f(" + (float) p + ", " + (float) pO + ") = " + (float) res);
        writeToFile("theoreticalDop32.txt", (float) res, (float) p, (float) pO);
    }

    public static void practiceDop32(double p, double pO, int n, int e) {
        int count = 0;
        for (int i = 0; i < e; i++) {
            for (int j = 0; j < n; j++) {
                double randDirect = Math.random();
                double randReverse = Math.random();
                count++;
                if (p < randDirect && pO < randReverse) {
                    break;
                }
            }
        }
        double res = (double) count / e;
        System.out.println("Practice res = " + (float) res);
        writeToFile("practiceDop32.txt", (float) res, (float) p, (float) pO);
    }

    public static void dop4(boolean filling, int e, int t) throws Exception {
        System.out.println("********************");
        System.out.println("Task 4");

        if (filling && e == 0 && t == 0) {
            e = readNumberExperiments();
            double p = readErrorProbability();
            t = readDelayTime(e);

            theoreticalDop4(p, t);
            practiceDop4(e, p, t);
        } else if (!filling && e > 0) {
            for (double p = 0; p <= 0.9; p += 0.1) {
                theoreticalDop4(p, t);
                practiceDop4(e, p, t);
            }
        } else {
            throw new Exception("Incorrect parameters");
        }
        System.out.println("********************");
    }

    public static void theoreticalDop4(double p, int t) {
        double nu = (1 - p) / (1 + t);
        System.out.println("Theoretical: nu(" + t + ", " + (float) p + ") = " + (float) nu);
        writeToFile("theoreticalDop4.txt", (float) nu, (float) p);
    }

    public static void practiceDop4(int e, double p, int t) {
        int T = 0;
        for (int i = 1; i <= e; i++) {
            T += t + 1;
            writeToLogFile("LogDop4.txt", "Сообщение " + i + " отправлено.");
            while (Math.random() <= p) {
                writeToLogFile("LogDop4.txt", "Отрицательная квитанция " + i);
                writeToLogFile("LogDop4.txt", "Повторная отправка сообщения " + i);
                T += t + 1;
            }
            writeToLogFile("LogDop4.txt", "Положительная квитанция " + i);
        }
        double nu = (double) e / T;
        System.out.println("Practice: nu(" + t + ", " + (float) p + ") = " + (float) nu);
        writeToFile("practiceDop4.txt", (float) nu, (float) p);
    }

    public static void dop5(boolean filling, int e, int t) throws Exception {
        System.out.println("********************");
        System.out.println("Task 5");
        List<Entry> messages = new ArrayList<>();

        /*for (double p = 0; p <= 0.9; p += 0.1) {
            theoreticalDop5(p, t);
            practiceDop5(e, p, t, messages);
        }*/

        if (filling && e == 0 && t == 0) {
            e = readNumberExperiments();
            double p = readErrorProbability();
            t = readDelayTime(e);

            theoreticalDop5(p, t);
            practiceDop5(e, p, t, messages);
        } else if (!filling && e > 0 && t > 0) {
            for (double p = 0; p <= 0.9; p += 0.1) {
                theoreticalDop5(p, t);
                practiceDop5(e, p, t, messages);
            }
        } else {
            throw new Exception("Incorrect parameters");
        }
        System.out.println("********************");
    }

    public static void theoreticalDop5(double p, int t) {
        double nu = (1 - p) / (1 + p * t);
        System.out.println("Theoretical: nu(" + t + ", " + (float) p + ") = " + (float) nu);
        writeToFile("theoreticalDop5.txt", (float) nu, (float) p);
    }

    public static void practiceDop5(int e, double p, int t, List<Entry> messages) {
        int T = 0;
        for (int i = 0; i <= t; i++) {
            writeToLogFile("LogDop5.txt", "Передается сообщение " + i);
            System.out.println("Передается сообщение " + i);
            sending(i, p, messages, "LogDop5.txt");
            T++;
        }
        int count = e + t + 1;
        int message = t + 1;
        for (int i = t + 1; i < count; i++) {
            if (!messages.get(i - t - 1).isSent()) {
                System.out.println("Повторная отправка сообщения " + messages.get(i - t - 1).getIndex());
                sending(messages.get(i - t - 1).getIndex(), p, messages, "LogDop5.txt");
                markUnsentMessage(i - t - 1, messages);
                count += t + 1;
                T++;
            } else {
                if (message < e) {
                    System.out.println("Передается сообщение " + message);
                    sending(message, p, messages, "LogDop5.txt");
                    message++;
                    T++;
                } else {
                    System.out.println("Канал ожидает квитанцию");
                    messages.add(new Entry(-1, true));
                }
            }
        }
        double nu = (double) e / T;
        System.out.println("Practice: nu(" + t + ", " + (float) p + ") = " + (float) nu);
        writeToFile("practiceDop5.txt", (float) nu, (float) p);
    }

    public static void sending(int index, double p, List<Entry> messages, String fileName) {
        if (Math.random() <= p) {
            messages.add(new Entry(index, false));
            writeToLogFile(fileName, "Сообщение " + index + " не доставлено");
            System.out.println("Сообщение " + index + " не доставлено");
        } else {
            messages.add(new Entry(index, true));
            writeToLogFile(fileName, "Сообщение " + index + " доставлено");
            System.out.println("Сообщение " + index + " доставлено");
        }
    }

    public static void markUnsentMessage(int index, List<Entry> messages) {
        for (Entry msg : messages) {
            if (msg.getIndex() > index && msg.isSent()) {
                msg.setSent(false);
                System.out.println("Сообщение " + msg.getIndex() + " было удалено");
            }
        }
    }

    public static int indexReceivedMsg = -1;

    public static void base() throws Exception {
        System.out.println("********************");
        System.out.println("Base task");
        int numExp = 1000;
        //double p = 0.3;
        int t = 4;

        for (double p = 0.0; p <= 0.9; p += 0.1) {
            theoreticalBase(p, t);
            practiceBase(numExp, p, t);
            indexReceivedMsg = -1;
        }

//        practiceBase(numExp, p, t);
//        indexReceivedMsg = -1;
        System.out.println("********************");
    }

    private static void theoreticalBase(double p, int t) {
        double nu = (1 + p - 2 * p * p) / (1 + p + p * t + p * p * t);
        System.out.println("Theoretical: nu(" + t + ", " + (float) p + ") = " + (float) nu);
        writeToFile("theoreticalBase.txt", (float) nu, (float) p);
    }

    private static void practiceBase(int numExp, double p, int t) {
        int countSent = 0;
        List<Entry> messages = new ArrayList<>();
        Buffer buffer = new Buffer();
        String logNameFile = "LogBase.txt";

        for (int i = 0; i <= t; i++) {
            System.out.println("Передается сообщение " + i);
            writeToLogFile(logNameFile, "Передается сообщение " + i);
            sendingForBase(i, p, messages, logNameFile, buffer);
            countSent++;
        }
        int countResent = numExp;
        int message = t + 1;
        for (int i = 0; i < countResent; i++) {
            if (!messages.get(i).isSent()) {
                System.out.println("Повторная отправка сообщения " + messages.get(i).getIndex());
                sendingForBase(messages.get(i).getIndex(), p, messages, logNameFile, buffer);
                countResent += t + 1;
                countSent++;
            } else {
                if (message < numExp) {
                    System.out.println("Передается сообщение " + message);
                    sendingForBase(message, p, messages, logNameFile, buffer);
                    message++;
                    countSent++;
                } else {
                    //System.out.println("Канал ожидает квитанции");
                    messages.add(new Entry(-1, true));
                }
            }
        }
        double nu = (double) numExp / countSent;
        System.out.println("Practice: nu(" + t + ", " + (float) p + ") = " + (float) nu);
        writeToFile("practiceBase.txt", (float) nu, (float) p);
    }

    public static void sendingForBase(int index, double p, List<Entry> messages, String fileName, Buffer buffer) {
        if (Math.random() <= p) {
            messages.add(new Entry(index, false));
            writeToLogFile(fileName, "Сообщение " + index + " не доставлено");
            System.out.println("Сообщение " + index + " не доставлено");
        } else {
            if (indexReceivedMsg + 1 == index) {
                System.out.println("Сообщение " + index + " доставлено");
                writeToLogFile(fileName, "Сообщение " + index + " доставлено");
                messages.add(new Entry(index, true));
                indexReceivedMsg++;
                if (!buffer.isEmpty()) {
                    if (buffer.getIndex() == indexReceivedMsg + 1) {
                        System.out.println("Сообщение " + buffer.getIndex() + " стерто из буфера и записано в память");
                        writeToLogFile(fileName, "Сообщение " + buffer.getIndex() + " стерто из буфера и записано в память");
                        messages.add(new Entry(buffer.getIndex(), true));
                        indexReceivedMsg++;
                        buffer.clear();
                    }
                }
            } else if (buffer.isEmpty) {
                System.out.println("Сообщение " + index + " записано в буфер");
                writeToLogFile(fileName, "Сообщение " + index + " записано в буфер");
                buffer.setIndex(index);
            } else {
                System.out.println("Сообщение " + index + " доставлено, но удалено");
                writeToLogFile(fileName, "Сообщение " + index + " доставлено, но удалено");
                messages.add(new Entry(index, false));
            }
        }
    }

    public static class Entry {
        private final int index;
        private boolean isSent;

        public Entry(int index, boolean isSent) {
            this.index = index;
            this.isSent = isSent;
        }

        public boolean isSent() {
            return isSent;
        }

        public int getIndex() {
            return index;
        }

        public void setSent(boolean isSent) {
            this.isSent = isSent;
        }
    }

    public static class Buffer {
        private int index;
        private boolean isEmpty;

        public Buffer() {
            this.isEmpty = true;
        }

        public void setIndex(int index) {
            this.index = index;
            this.isEmpty = false;
        }

        public boolean isEmpty() {
            return isEmpty;
        }

        public int getIndex() {
            if (isEmpty) {
                return -1;
            }
            return index;
        }

        public void clear() {
            this.index = -1;
            this.isEmpty = true;
        }
    }

    public static void clearAllFile() {
        System.out.println("Все файлы очищены");
        List<String> nameFiles = new ArrayList<>();
        nameFiles.add("practiceDop1.txt");
        nameFiles.add("practiceDop2.txt");
        nameFiles.add("practiceDop31.txt");
        nameFiles.add("practiceDop32.txt");
        nameFiles.add("practiceDop4.txt");
        nameFiles.add("practiceDop5.txt");
        nameFiles.add("theoreticalDop1.txt");
        nameFiles.add("theoreticalDop2.txt");
        nameFiles.add("theoreticalDop31.txt");
        nameFiles.add("theoreticalDop32.txt");
        nameFiles.add("theoreticalDop4.txt");
        nameFiles.add("theoreticalDop5.txt");
        nameFiles.add("LogDop4.txt");
        nameFiles.add("LogDop5.txt");
        nameFiles.add("theoreticalBase.txt");
        nameFiles.add("practiceBase.txt");

        try {
            for (String nameFile : nameFiles) {
                FileWriter fw = new FileWriter(nameFile);
                fw.write("");
                fw.close();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void writeToFile(String nameFile, float res, float p) {
        try (FileWriter fw = new FileWriter(nameFile, true)) {
            fw.write("(" + p + "; " + res + ")\n");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void writeToFile(String nameFile, float res, float p, float pO) {
        try (FileWriter fw = new FileWriter(nameFile, true)) {
            fw.write("(" + p + "; " + pO + "; " + res + ")\n");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void writeToLogFile(String nameFile, String message) {
        try (FileWriter fw = new FileWriter(nameFile, true)) {
            fw.write(message + "\n");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static int readNumberExperiments() throws Exception {
        System.out.print("Количество испытаний e = ");
        int e = sc.nextInt();
        if (e < 0) {
            throw new Exception("Incorrect data. Variable e should be greater than zero.");
        }
        return e;
    }

    public static double readErrorProbability() throws Exception {
        System.out.print("Вероятность ошибки в прямом канале p = ");
        double p = sc.nextDouble();
        if (p > 1.0 || p < 0.0) {
            throw new Exception("Incorrect data. Variable p should be less than one and greater than zero.");
        }
        return p;
    }

    public static int readNumberOfResubmissions(int e) throws Exception {
        System.out.print("Количество повторных передач n = ");
        int n = sc.nextInt();
        if (n < 0 || n > e) {
            throw new Exception("Incorrect data." +
                    "Variable n should be greater than zero and less than number of experiments.");
        }
        return n;
    }

    public static int readDelayTime(int e) throws Exception {
        System.out.print("Время задержки t = ");
        int t = sc.nextInt();
        if (t < 0 || t > e) {
            throw new Exception("Incorrect data." +
                    "Variable t should be greater than zero and less than number of experiments.");
        }
        return t;
    }
}