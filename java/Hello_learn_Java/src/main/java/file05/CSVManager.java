package file05;

import java.io.*;
import java.util.ArrayList;


//add:zhang,zhang,67890
//show:
//del:Ling
//done

public class CSVManager {
    public static final String FILE_NAME = "salary.csv";

    public static void main(String[] args){
        //1. Loop: input a command,until "done"


        boolean isStop = false;

        do{
            //1.1 get a command from console
            String s = inputString("Enter a command:");
            if(s.equals("done"))
                isStop = true;
            else {
                //1.2 parse a command, add
                String[] cmdList = parseCMD(s);
                //1.3 execute
                switch (cmdList[0]) {
                    case "add":
                        add(FILE_NAME,cmdList[1]);
                        break;
                    case "del":
                        del();
                        break;
                    case "show":
                        show(FILE_NAME);
                        break;
                    default:
                        System.out.println("Wrong Command!");
                }
                //1.4 output
            }
        }while(!isStop);
    }

    public static ArrayList<String> readCSV(String filename){
        ArrayList<String> a = new ArrayList<String>();

        try{
            File myFile = new File(filename);
            FileReader fileReader = null;
            fileReader = new FileReader((myFile));
            BufferedReader reader = new BufferedReader(fileReader);

            String line = null;

            while((line=reader.readLine())!=null){
                a.add(line);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return  a;

    }
    public static void add(String filename,String line){
        FileWriter fw = null;
        try {
            fw = new FileWriter(filename,true);
            fw.write(line+"\n");
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void del(){

    }
    public static void show(String filename){

        ArrayList<String> list = readCSV(filename);

        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }

    }
    public static String[] parseCMD(String command){
        String[] list = command.split(":");
        return list;
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
