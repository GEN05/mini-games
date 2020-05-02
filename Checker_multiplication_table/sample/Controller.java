package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;

import java.io.IOException;

import static javafx.scene.paint.Color.BLACK;
import static javafx.scene.paint.Color.RED;

public class Controller {

    @FXML
    private TextField num2Field;

    @FXML
    private ProgressBar progress;

    @FXML
    private Label text;

    @FXML
    private TextField resultField;

    @FXML
    private TextField num1Field;

    public Controller() {
    }

    @FXML
    void press(KeyEvent event) throws IOException {
        switch (event.getCode().toString()) {
            case "BACK_SPACE":
            case "DELETE":
                resultField.setText("");
                break;
            case "DIGIT0":
                zero();
                break;
            case "DIGIT1":
                one();
                break;
            case "DIGIT2":
                two();
                break;
            case "DIGIT3":
                three();
                break;
            case "DIGIT4":
                four();
                break;
            case "DIGIT5":
                five();
                break;
            case "DIGIT6":
                six();
                break;
            case "DIGIT7":
                seven();
                break;
            case "DIGIT8":
                eight();
                break;
            case "DIGIT9":
                nine();
                break;

        }
    }

    @FXML
    void zero() {
        resultField.setText(resultField.getText() + "0");
    }

    @FXML
    void one() {
        resultField.setText(resultField.getText() + "1");
    }

    @FXML
    void two() {
        resultField.setText(resultField.getText() + "2");
    }

    @FXML
    void three() {
        resultField.setText(resultField.getText() + "3");
    }

    @FXML
    void four() {
        resultField.setText(resultField.getText() + "4");
    }

    @FXML
    void five() {
        resultField.setText(resultField.getText() + "5");
    }

    @FXML
    void six() {
        resultField.setText(resultField.getText() + "6");
    }

    @FXML
    void seven() {
        resultField.setText(resultField.getText() + "7");
    }

    @FXML
    void eight() {
        resultField.setText(resultField.getText() + "8");
    }

    @FXML
    void nine() {
        resultField.setText(resultField.getText() + "9");
    }

    @FXML
    void ok() throws IOException {
        if (num1Field.getText().equals("") || resultField.getText().equals("")) {
            num1Field.setText(Integer.toString(Model.random()));
            num2Field.setText(Integer.toString(Model.random()));
            resultField.setText("");
            progress.setProgress(progress.getProgress() - 0.2);
        } else {
            String sResult = resultField.getText();
            int num1 = Integer.parseInt(num1Field.getText());
            int num2 = Integer.parseInt(num2Field.getText());
            int result = Integer.parseInt(sResult);
            if (Model.checker(num1, num2, result)) {
                text.setTextFill(BLACK);
                text.setText("Верно!");
                progress.setProgress(progress.getProgress() + 0.2);
                if (progress.getProgress() > 1) {
                    final long finnish_time = System.currentTimeMillis();
                    Main.fin(finnish_time);
                    System.exit(0);
                }
            } else {
                text.setTextFill(RED);
                Model.writeMistake(num1, num2);
                text.setText("Неверно, попробуй ещё");
                progress.setProgress(0);
            }
            resultField.setText("");
            num1Field.setText(Integer.toString(Model.random()));
            num2Field.setText(Integer.toString(Model.random()));
        }
    }
}
