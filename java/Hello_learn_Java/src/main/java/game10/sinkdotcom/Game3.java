package game10.sinkdotcom;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Game3 {

    Map3 m ;

    private int count =0;
    private int left =3;  // company number


    public int getLeft(){
        return left;
    }

    public void countPlus(){
        count++;
    }
    public void leftMinus(){
        left--;
    }
    public void play(){
        boolean isOver = false;
        //1. initialization the map
        init();
        //2. start
        //2.1 input your guess
        //2.2 judge
        do{
            String s =inputString("Enter your guess(From A0 to F6):");

            countPlus();

            System.out.println(s);

            int i =0;
            int j =0;

            i = s.charAt(0)-'A';
            j = s.charAt(1)-'0';

            System.out.println(i+ " " +j);

            String result = m.judge(i,j);

            System.out.println(result);

            if (result.equals("kill"))
                leftMinus();

            if(getLeft()==0)
                isOver = true;

        }while(!isOver);
        //3. finish
        finish();

    }
    public static void main(String[] args){
        Game3 g = new Game3();
        g.play();
    }
    public void init(){

        m = new Map3();

    }
    public void finish(){
        System.out.print("You have guessed "+count+" Steps.");
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
