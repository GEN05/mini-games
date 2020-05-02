package ticTacToe;

import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Tournament {
    private final boolean log;
    private final Player[] players = new Player[10];
    private int[] score = new int[10];

    public Tournament(final boolean log, final Player player1, final Player player2) {
        this.log = log;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                this.players[i] = player1;
            } else {
                this.players[i] = player2;
            }
        }
    }

    public int start() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите m, n, k, c, rep: ");
        boolean flag = true;
        try {
            int m = sc.nextInt(), n = sc.nextInt(), k = sc.nextInt(), c = sc.nextInt(), rep = sc.nextInt();
            flag = false;
            if (m <= 0 || n <= 0 || k <= 0 || c <= 1 || rep <= 0) {
                System.err.println("Incorrect input (<= 0)");
                start();
            }
//            if (k > m || k > n) {
//                System.err.println("Incorrect input (k > m || n)");
//                start();
//            }
            for (int r = 0; r < rep; r++) {
                for (int i = 0; i < c - 1; i++) {
                    for (int j = i + 1; j < c; j++)
                        play(new MNKBoard(m, n, k), i, j);
                }
            }
        } catch (InputMismatchException e) {
            System.err.println("Incorrect input (letters)");
            if (flag) start();
        } catch (NoSuchElementException e) {
            System.err.println("Empty input");
        }
        return 0;
    }

    public int play(Board board, int p1, int p2) {
        while (true) {
            for (int i = p1; i < p2 + 1; i += p2 - p1) {
                final int result = move(board, i, p2);
                if (result != -1) {
                    return result;
                }
            }
        }
    }

    private int move(final Board board, final int no, int no2) {
        final Move move = players[no].move(board.getPosition(), board.getCell());
        final Result result = board.makeMove(move);
        log("Player " + (no + 1) + " move: " + move);
        log("Position:\n" + board);
        if (result == Result.WIN) {
            score[no + 1] += 3;
            log("Player " + (no + 1) + " won");
            getTable();
            return no;
        } else if (result == Result.LOSE) {
            log("Player " + (no + 1) + " lose");
            getTable();
            return 3 - no;
        } else if (result == Result.DRAW) {
            score[no + 1] += 1;
            score[no2 + 1] += 1;
            log("Draw");
            getTable();
            return 0;
        } else {
            return -1;
        }
    }

    private void getTable() {
        System.out.println("Игрок : очки");
        int t = 1;
        for (int i = 0; i < 10; i++) if (score[i] != 0) t = i + 1;
        for (int i = 1; i < t; i++) {
            System.out.print(i);
            System.out.print(" : ");
            System.out.println(score[i]);
        }
    }

    private void log(final String message) {
        if (log) {
            System.out.println(message);
        }
    }
}
