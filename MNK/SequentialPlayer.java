package ticTacToe;

public class SequentialPlayer implements Player {
    @Override
    public Move move(final Position position, final Cell cell) {
        for (int r = 0; r < position.GetN(); r++) {
            for (int c = 0; c < position.GetM(); c++) {
                final Move move = new Move(r, c);
                if (position.isValid(move)) {
                    return move;
                }
            }
        }
        throw new IllegalStateException("No valid moves");
    }
}
