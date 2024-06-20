package game10.sinkdotcom;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Game22 {
    private int[][] map = new int[7][7];
    private int count =0;
    private int left =3;// number of dotcom

    public int getLeft(){
        return left;
    }
    public int getPositionI(int i,int j){
        return map[i][j];

    }
    public void clearPostionI(int i,int j){
        map[i][j]=0;
    }
    public void countPlus(){
        count++;
    }
    public void leftMinus(){
        left--;
    }
    public boolean indexof(int value){
        boolean result =false;

        for(int i =0;i<map.length;i++)
            for(int j =0;j<map[0].length;j++)
                if(map[i][j]==value) {
                    result = true;
                    break;
                }

        return  result;
    }

    public static void main(String[] args){
        Game22 g = new Game22();
        boolean isOver = false;

        //1. initialization the map
        g.init();
        //2. start
        //2.1 input your guess
        //2.2 judge
        do{
            String s =g.inputString("Enter your guess(From A0 to F6):");

            int i = s.charAt(0)-'A';
            int j = s.charAt(1)-'0';

            g.countPlus();

            System.out.println(i+","+j);

            int status = g.getPositionI(i,j);

            if(status>0){
                g.clearPostionI(i,j);

                if(g.indexof(status)) {
                    g.leftMinus();
                    System.out.println("kill");
                }
                else System.out.println("hit");
            }else{
                System.out.println("miss");
            }

            if(g.getLeft()==0)
                isOver = true;

        }while(!isOver);
        //3. finish
        g.finish();
    }
    public void init(){
        map[0][0] = 1; //A0
        map[0][1] = 1; //A1
        map[0][2] = 1; //A2
        map[2][0] = 2; //C0
        map[3][0] = 2; //D0
        map[4][0] = 2; //E0
        map[4][4] = 3; //E4
        map[4][5] = 3; //E5
        map[4][6] = 3; //E6
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
