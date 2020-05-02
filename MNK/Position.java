package ticTacToe;

public interface Position {
    boolean isValid(Move move);

    int GetN();

    int GetM();
}
