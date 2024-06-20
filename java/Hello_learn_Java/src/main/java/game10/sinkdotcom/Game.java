package game10.sinkdotcom;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Game {
    private int[] map = new int[7];
    private int count =0;
    private int left =3;

    public int getLeft(){
        return left;
    }
    public int getPositionI(int i){
        return map[i];

    }
    public void clearPostionI(int i){
        map[i]=0;
    }
    public void countPlus(){
        count++;
    }
    public void leftMinus(){
        left--;
    }
    public static void main(String[] args){
        Game g = new Game();
        boolean isOver = false;

        //1. initialization the map
        g.init();
        //2. start
        //2.1 input your guess
        //2.2 judge
        do{
            int i =g.inputInt("Enter your guess(From 0 to 6):");

            g.countPlus();

            System.out.println(i);

            if(g.getPositionI(i)==1){
                g.clearPostionI(i);
                g.leftMinus();
                System.out.println("hit");
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
//        long seed = System.currentTimeMillis();
//        Random seedRandom = new Random(seed);
//        int p = seedRandom.nextInt(5); // 4
        int p = (int)(Math.random()*5);//4
        map[p++] = 1;
        map[p++] = 1;
        map[p] = 1; //{0,0,0,0,1,1,1}
    }
    public void finish(){
        System.out.print("You have guessed "+count+" Steps.");
    }

    public int inputInt(String prompt) {
        String temp = "";
        try {
            System.out.println(prompt);
            BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
            temp = br1.readLine();

        }
        catch(IOException e) {
            e.printStackTrace();
        }

        return Integer.parseInt(temp);
    }
}
