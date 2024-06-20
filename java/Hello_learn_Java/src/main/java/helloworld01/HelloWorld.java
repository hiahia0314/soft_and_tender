package helloworld01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args){

        twoIntAdd();

    }
    public static int add(int i,int j){
        int result = i + j;
        return result;
    }


    public static void twoIntAdd(){
        int one=0;
        int two=0;
        int sum = 0;
        String temp=null;

        try {
/**处理输入
 * or   Scanner input=new Scanner(System.in);
 */
            System.out.println("please enter the first integer:");
            BufferedReader br1=new BufferedReader(new InputStreamReader(System.in));
            temp=br1.readLine();// 1、输入
            one=Integer.parseInt(temp); // 2.1 处理(转为int)

            System.out.println("please enter the second integer:");
            BufferedReader br2=new BufferedReader(new InputStreamReader(System.in));
            temp=br2.readLine();
            two=Integer.parseInt(temp);

        } catch (IOException e) {
            e.printStackTrace();
        }

        sum = add(one,two); // 2.2 、处理（求和）
        System.out.println(one+"+"+two+"="+sum);// 3、输出
    }
}
