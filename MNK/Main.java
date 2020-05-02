package ticTacToe;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        //final Game game = new Game(true, new HumanPlayer(), new RandomPlayer());
        //game.start();
        final Tournament tournament = new Tournament(true, new RandomPlayer(), new RandomPlayer());
        tournament.start();
    }
}
