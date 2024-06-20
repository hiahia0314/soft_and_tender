package game10.pingpong;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ClassicGame {
    Set set = new Set();
    int scoreA=0;
    int scoreP=0;

    public void init(){

        //show the set and game info

    }

    public void run(){

        boolean isOver = false;

        init();


        do{
            String result = set.playOneSet();

            if(result.equals("A"))
                scoreA++;
            else if(result.equals("P"))
                scoreP++;


            System.out.println("========================");
            System.out.println("A:"+scoreA);
            System.out.println("P:"+scoreP);

            if(scoreA==5 || scoreP == 5) {
                isOver = true;
                break;
            }

            String s =inputString("Continue(C) or Quit(Q)?");

            if(s.equals("Q")) {
                quit();
                break;
            }

        }while(!isOver);

        finish();

    }
    public void win(){
        if(scoreA>scoreP)
            System.out.println("Agent Win!");
        else
            System.out.println("Player Win !");
    }

    public void quit(){

    }
    public void finish(){
        win();
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
