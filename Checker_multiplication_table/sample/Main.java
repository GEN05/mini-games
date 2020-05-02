package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Scanner;


public class Main extends Application {

    private static long start_time;

    @Override
    public void start(Stage primaryStage) throws Exception {
        start_time = System.currentTimeMillis();
        Parent root = FXMLLoader.load(getClass().getResource("View.fxml"));
        primaryStage.setTitle("Проверка таблицы умножения");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }


    void main(String[] args) {
        launch(args);
    }

    static void fin(long finnish_time) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Как тебя зовут?");
        String name = sc.nextLine();
        Model.writeRecord(((finnish_time - start_time) / 1000), name);
        System.out.println((finnish_time - start_time) / 1000);
    }
}
