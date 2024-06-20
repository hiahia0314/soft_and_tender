package game10.sinkdotcom;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Game2 {
    private int[][] map = new int[7][7];//1D-2D
    private int count =0;
    private int left =3;  // company number


    public int getLeft(){
        return left;
    }
    public int getPositionI(int i,int j){
        return map[i][j];

    }
    public boolean indexof(int n){
        boolean hasIt = false;
        for(int i=0;i<map.length;i++){
            for(int j =0;j<map[0].length;j++)
                if(map[i][j]==n) {
                    hasIt = true;
                    break;
                }
        }
        return hasIt;
    }

    public void clearPostionI(int i,int j){
        map[i][j]=map[i][j]*(-1);
    }
    public void countPlus(){
        count++;
    }
    public void leftMinus(){
        left--;
    }
    public void play() throws MyException {
        boolean isOver = false;
        //1. initialization the map
        init();
        //2. start
        //2.1 input your guess
        //2.2 judge
        do{
            String s =inputString("Enter your guess(From 0 to 6):");

            countPlus();

            System.out.println(s);

            int i =0;
            int j =0;

            i = s.charAt(0)-'A';
            j = s.charAt(1)-'0';

            System.out.println(i+ "" +j);

            int status =getPositionI(i,j);
            if(status>0){
                clearPostionI(i,j);
                if(indexof(status))
                    System.out.println("hit");
                else {
                    System.out.println("kill");
                    leftMinus();
                }
            }else{
                System.out.println("miss");
            }

            if(getLeft()==0)
                isOver = true;

        }while(!isOver);
        //3. finish
        finish();

        throw new MyException();

    }
    public static void main(String[] args){
        Game2 g = new Game2();
        try {
            g.play();
        } catch (MyException e) {
            e.printStackTrace();
        }
    }
    public void init(){

//        long seed = System.currentTimeMillis();
//        Random seedRandom = new Random(seed);
//        int p = seedRandom.nextInt(5); // 4
//        map[p++] = 1;
//        map[p++] = 1;
//        map[p] = 1; //{0,0,0,0,1,1,1}
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
        catch(Exception e) {
            e.printStackTrace();
        }
        finally {

        }

        return temp;
    }
}
