package branch03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DataAnalysis2 {

    public static int length=0;


    public static void main(String[] args){
        int[] numArray;
        double average;

        //1. input
        numArray = inputNumArray();

        //2. calculate
        average = calculateAverage(numArray);

        //3. output
        ouput(average);
    }

    private static void ouput(double average) {
        System.out.println(average);
    }


    private static double calculateAverage(int[] numArray) {
        double average = 0;
        int sum = 0;

        for(int i= 0;i<length; i++) {
            sum = sum +numArray[i];
        }

        average = sum * 1.0 / length;

        return average;

    }

    private static int[] inputNumArray() {
        int[] na = new int[100];
        String s = "";
        boolean isStop = false;

        do{
            s = inputString("Enter a number:");
            if(s.equals("done"))
                isStop = true;
            else
                na[length++] = Integer.parseInt(s);
        }while(!isStop);

        return na;
    }

    public static String inputString(String prompt) {
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
