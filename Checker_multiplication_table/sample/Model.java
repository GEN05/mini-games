package sample;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;
import java.util.Random;

class Model {
    static int random() {
        Random rand = new Random();
        return 2 + rand.nextInt(7);
    }
    static boolean checker(int a, int b, int c) {
        return a * b == c;
    }
    static void writeMistake(int a, int b) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("mistake.txt", true), StandardCharsets.UTF_8))) {
            writer.write(a + " * " + b + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void writeRecord(long time, String name) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("record.txt", true), StandardCharsets.UTF_8))) {
            writer.write(name + "  " + time + " секунд\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
