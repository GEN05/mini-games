package ticTacToe;

import java.util.Random;

public class RandomPlayer implements Player {
    private final Random random;

    public RandomPlayer(final Random random) {
        this.random = random;
    }

    public RandomPlayer() {
        this(new Random());
    }

    @Override
    public Move move(final Position position, final Cell cell) {
        while (true) {
            int r = random.nextInt(position.GetN());
            int c = random.nextInt(position.GetM());
            final Move move = new Move(r, c);
            if (position.isValid(move)) {
                return move;
            }
        }
    }
}
