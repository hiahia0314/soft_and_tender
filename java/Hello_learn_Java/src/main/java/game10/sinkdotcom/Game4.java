package game10.sinkdotcom;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Game4 {

    Map4 m ;

    private boolean isXTurn = true;
    private String result = "Gaming";

    public void play(){
        boolean isOver = false;
        //1. initialization the map
        init();
        //2. start
        //2.1 input your guess
        //2.2 judge
        do{
            String s =inputString("Enter your Move(like A0):");

            //System.out.println(s);

            int i =0;
            int j =0;

            i = s.charAt(0)-'A';
            j = s.charAt(1)-'0';

            //System.out.println(i+ " " +j);

            result = m.move(i,j,isXTurn);

            System.out.println(result);

            if (result.equals("X_Win")||result.equals("O_Win")||result.equals("Draw"))
                isOver = true;

            isXTurn = !isXTurn;

        }while(!isOver);
        //3. finish
        finish();

    }
    public static void main(String[] args){
        Game4 g = new Game4();
        g.play();
    }
    public void init(){

        m = new Map4();

    }
    public void finish(){
        System.out.print(result);
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
