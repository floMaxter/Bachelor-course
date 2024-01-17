package com.ml.lab2;

import com.ml.lab2.network.NNetwork;
import com.ml.lab2.utils.Pair;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.function.UnaryOperator;

public class Main {
    public static final Integer COUNT_NEURONS_INPUT_LAYER = 784;
    public static final String datasetNameFile = "Dataset.csv";
    public static final String graphAccuracyFileName = "graphAccuracy.txt";
    public static final String graphMSELossFileName = "graphMSELoss.txt";

    public static UnaryOperator<Double> sigmoid = x -> 1 / (1 + Math.exp(-x));
    public static UnaryOperator<Double> dsigmoid = y -> y * (1 - y);

    public static void main(String[] args) {
        try (FileInputStream dataFromDataset = new FileInputStream(datasetNameFile);
             DataInputStream inputDataset = new DataInputStream(dataFromDataset);
             PrintWriter writerAccuracy = new PrintWriter(graphAccuracyFileName);
             PrintWriter writerMSE = new PrintWriter(graphMSELossFileName)) {

            NNetwork nnetwork = new NNetwork(0.001, sigmoid, dsigmoid, COUNT_NEURONS_INPUT_LAYER, 512, 128, 32, 10);

            /*            int samples = 1000;
            Pair[] arrValObj = new Pair[samples];
            double[][] inputs = new double[samples][NEURONS];

            String currLine;
            String[] lines;
            while ((currLine = inputDataset.readLine()) != null) {
                lines = currLine.split(",");
                int sampInd = Integer.parseInt(lines[0]);
                if (sampInd != samples) {
                    int digitValObj = (int) (Math.ceil(sampInd / 100)) + 1;
                    Pair<Integer, String> validObject = new Pair(digitValObj, lines[1]);
                    arrValObj[sampInd] = validObject;
                    for (int j = 0; j < NEURONS; j++) {
                        inputs[sampInd][j] = Integer.parseInt(lines[j + 2]);
                    }
                }
            }

            int epochs = 30;
            for (int i = 1; i <= epochs; i++) {
                double right = 0;
                double errorSum = 0;
                double accuracy = 0;
                int batchSize = 1000;

                for (int j = 0; j < batchSize; j++) {
                    int imgIndex = j;
                    double[] targets = new double[10];
                    int digit = (int) arrValObj[imgIndex].getFirst();
                    targets[digit] = 1;

                    double[] outputs = nnetwork.feedForward(inputs[imgIndex]);
                    int maxDigit = 0;
                    double maxDigitWeight = -1;
                    for (int k = 0; k < 10; k++) {
                        if (outputs[k] > maxDigitWeight) {
                            maxDigitWeight = outputs[k];
                            maxDigit = k;
                        }
                    }
                    if (digit == maxDigit) right++;
                    for (int k = 0; k < 10; k++) {
                        errorSum += (targets[k] - outputs[k]) * (targets[k] - outputs[k]);
                    }
                    nnetwork.backpropagation(targets);
                    accuracy = right / batchSize;
                }
                System.out.println("Epoch: " + i + ". Accuracy: " + accuracy + ". MSE Loss: " + errorSum / 10);
                writerAccuracy.println(accuracy);
                writeMSE.println(errorSum / 10);*/

            int samples = 800;
            Pair[] arrValObj = new Pair[samples];
            double[][] inputs = new double[samples][COUNT_NEURONS_INPUT_LAYER];

            String thisLine;
            String[] line;
            while ((thisLine = inputDataset.readLine()) != null) {
                line = thisLine.split(",");
                int sampInd = Integer.parseInt(line[0]);

                if (sampInd == 800) break;
                int digitValObj = (int) (Math.ceil(sampInd / 100)) + 1;
                Pair<Integer, String> validObject = new Pair(digitValObj, line[1]);
                arrValObj[sampInd] = validObject;
                for (int j = 0; j < COUNT_NEURONS_INPUT_LAYER; j++) {
                    inputs[sampInd][j] = Integer.parseInt(line[j + 2]);
                }
            }

            int epochs = 34;
            for (int i = 1; i <= epochs; i++)  {
                double right = 0;
                double errorSum = 0;
                double accuracy = 0;
                int batchSize = 800;

                for (int j = 0; j < batchSize; j++) {
                    int imgIndex = j;
                    double[] targets = new double[10];
                    int digit = (int) arrValObj[imgIndex].getFirst();
                    targets[digit] = 1;

                    double[] outputs = nnetwork.feedForward(inputs[imgIndex]);
                    int maxDigit = 0;
                    double maxDigitWeight = -1;
                    for (int k = 0; k < 10; k++) {
                        if (outputs[k] > maxDigitWeight) {
                            maxDigitWeight = outputs[k];
                            maxDigit = k;
                        }
                    }
                    if (digit == maxDigit) right++;
                    for (int k = 0; k < 10; k++) {
                        errorSum += (targets[k] - outputs[k]) * (targets[k] - outputs[k]);
                    }
                    nnetwork.backpropagation(targets);
                    accuracy = right / batchSize;
                }
                //System.out.println("Epoch: " + i + ". Accuracy: " + accuracy + ". MSE Loss: " + errorSum/10);
                System.out.println("(" + i + ";" + errorSum/10 + ")");
//                System.out.println("(" + i + "; " + accuracy + ")");

                writerAccuracy.println(accuracy);

                writerMSE.println(errorSum / 10);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
