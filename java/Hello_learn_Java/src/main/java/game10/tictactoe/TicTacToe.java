package game10.tictactoe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class TicTacToe {
    private int[][] map = new int[3][3];//1D-2D

    public void setPosition(int i, int j, boolean isX){
        if(isX) map[i][j] = 1;
        else map[i][j] = 2;
    }

    public void play() {//throws game10.sinkdotcom.MyException{
        boolean isOver = false;
        boolean isX = true;
        Result r = Result.GAMING;

        //1. initialization the map
        init();
        //2. start
        //2.1 input your guess
        //2.2 judge
        do{
            String s =inputString("Enter your guess(From A0 to F6):");


            int i =0;
            int j =0;

            i = s.charAt(0)-'A';
            j = s.charAt(1)-'0';

            System.out.println(i+ "" +j);

            setPosition(i,j,isX);

            r = judge();

            if(r!= Result.GAMING)
                isOver = true;

            isX = !isX;

            print();

        }while(!isOver);
        //3. finish
        finish(r);



    }
    public static void main(String[] args){
        TicTacToe g = new TicTacToe();
        g.play();
    }
    public void init(){

    }
    public Result judge(){
        Result r = Result.GAMING;

        if(map[0][0]==1&&map[0][1]==1&&map[0][2]==1 || map[1][0]==1&&map[1][1]==1&&map[1][2]==1 )
            r = Result.X_WIN;

        return r;
    }
    public void finish(Result r){
        switch (r){
            case X_WIN: System.out.println("X win!");break;
            case O_WIN: System.out.println("O win!");break;
            case DRAW: System.out.println("Draw!");break;
        }
    }

    public String inputString(String prompt) {
        String temp = "";
        try {
            System.out.println(prompt);
            BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
            temp = br1.readLine();

        }
        catch(IOException e) {
            e.printStackTrace();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        finally {

        }

        return temp;
    }
    public void print(){
        for(int i =0;i<3;i++) {
            for (int j = 0; j < 3; j++)
                System.out.print(toString(map[i][j]) + " ");
            System.out.println();
        }
    }
    public String toString(int n){
        String s ="";
        switch (n){
            case 0: s= "_";break;
            case 1: s= "X";break;
            case 2: s= "O";break;
        }
        return s;
    }


}
