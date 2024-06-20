package loop04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HeartRate {
    public static void main(String[] args){

        int restingPulse = 0;
        int age = 0;
        int[] heartRate;

        //1. Input resting pulse and age
        restingPulse = inputInt("Resting Pulse:");
        age = inputInt("Age:");

        //2. calculate the heat rate
        heartRate = calculateHeartRate(restingPulse,age);

        //3. output the table
        output(heartRate);
    }
    public static void output(int [] heartRate){
        System.out.println("Intensity|Rate");
        System.out.println("--------------");
//        for(int i =55;i<100;i+=5) {
//            System.out.println(i + "|" + heartRate[(i - 55) / 5]);
//        }
        int i =55;
        while(i<100)
        {
            System.out.println(i + "|" + heartRate[(i - 55) / 5]);
            i+=5;
        }
//          int i=55;
//          do{
//              System.out.println(i + "|" + heartRate[(i - 55) / 5]);
//              i+=5;
//          }while(i<=100);


    }
    public static int[] calculateHeartRate(int restingPulse, int age){
        int [] hr = new int [11];

        for(int i =55;i<100;i+=5){
            hr[(i-55)/5] = (((220-age)-restingPulse)*i/100)+restingPulse;
        }

        return hr;
    }
    public static int inputInt(String prompt) {
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
