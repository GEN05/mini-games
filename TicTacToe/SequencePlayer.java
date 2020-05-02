package TicTacToe;

public class SequencePlayer {

    public void makeMove(Position position, Ceil ceil) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (position.isVaild(r, c, ceil)) {
                    position.makeMove(r, c, ceil);
                }
            }
        }
    }
}
