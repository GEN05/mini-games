package TicTacToe;

public interface Position {
    boolean isVaild(int r, int c, Ceil ceil);

    void makeMove(int r, int c, Ceil ceil);
}
