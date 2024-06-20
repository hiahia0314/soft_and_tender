package branch03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DataAnalysis {
    public static void main(String[] args){
        //1. Input some numbers
        boolean isStop = false;
        int count = 0;
        int[] intArray = new int[100];
        double average;
        int min, max;
        int sd;

        do{
            String s = inputString("Enter a number:");
            if(s.equals("done"))
                isStop = true;
            else
                intArray[count++] = Integer.parseInt(s);
        }while(!isStop);

        //2. Process, average, min, max, standard deviation
        average = calculateAvarage(intArray,count);
        min = calculateMin(intArray,count);

        //3. Output
        output(average);
    }

    public static void output(double average){
        System.out.println(""+average);
    }
    public static int calculateMin(int[] array, int count){
        int min=array[0];
        for(int i=1;i<count;i++){
            if(array[i]<min) min = array[i];
        }
        return min;
    }

    public static double calculateAvarage(int[] array,int count) {
        int sum =0;

        for(int i =0;i<count;i++)
            sum += array[i];
//        for(int i : array)
//            sum+=i;
        return sum*1.0 / count;
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
