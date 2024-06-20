package game10.chess;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Chess {
    Map m;
    boolean isXTurn;
    GameResult state=GameResult.GAMING;

    public void init(){
        this.m = new OthelloMap();
        this.m.init();
        isXTurn=true;
    }

    public static void main(String[] args){
        Chess chess = new Chess();
        chess.init();
        chess.start();
    }

    public void start(){

        System.out.println("game.sinkdotcom.Game Start!");
        while(state==GameResult.GAMING){
            String move = inputString("Input your move:");

            int i = move.charAt(0)-'A';
            int j = move.charAt(1)-'0';


            state=m.judge(i,j,isXTurn);

            m.print();

            isXTurn= !isXTurn;

        }

        System.out.println("game.sinkdotcom.Game Finish: "+state);
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

        return temp;
    }
}
