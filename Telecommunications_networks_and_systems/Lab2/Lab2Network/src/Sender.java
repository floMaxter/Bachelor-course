import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Sender {
    private int messages;
    private List<Boolean> responseReceipt = new ArrayList<>();

    public Sender(int messages) {
        this.messages = messages;
    }

    public void sendMessages(int t) {
        if(messages == 0) {
            System.out.println("Сообщений нет");
        }
        for (int i = 1; i <= messages; i++) {
            if (i > t + 1) {
                
            }
            send(i);
        }

    }

    private void send(int numMessage) {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("communicationChannel.txt"))) {
            StringBuilder sb = new StringBuilder();
            sb.append("Отправлено ").append(numMessage).append(" сообщение");
            System.out.println(sb);
            bufferedWriter.write(sb.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
