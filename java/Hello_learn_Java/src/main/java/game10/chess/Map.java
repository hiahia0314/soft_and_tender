package game10.chess;

public abstract class Map {

    int count =0;

    int[][] map;

    public abstract void init();

    public abstract GameResult judge(int i, int j, boolean isXTurn);

    public abstract void print();
}
