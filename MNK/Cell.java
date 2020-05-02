package ticTacToe;

import java.util.Map;

public enum Cell {
    X, O, E;
    public static final Map<Cell, Character> SYMBOLS = Map.of(
            Cell.X, 'X',
            Cell.O, 'O',
            Cell.E, '.'
    );

    @Override
    public String toString() {
        return SYMBOLS.get(this).toString();
    }
}
