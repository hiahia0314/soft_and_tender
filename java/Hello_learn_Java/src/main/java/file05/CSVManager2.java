package file05;

import java.io.*;
import java.util.ArrayList;


//add:zhang,zhang,67890
//show:
//del:Ling
//done

public class CSVManager2 {


    public static void main(String[] args){
        //1 Loop: input your command,until "done"
        //1.1 parse your command, split to cmd and data
        //1.2 execute your command, switch
        //1.3 output your result.

        boolean isStop = false;
        String filename = "salary.csv";

        do{
            //1.1 parse your command, split to cmd and data

            String s = inputString("Enter a number:");
            if(s.equals("done"))
                isStop = true;
            else {
                //1.2 execute your command, switch
                //1.3 output your result.
                if(s.contains(":")) {
                    String[] cmdList = s.split(":");
                    switch (cmdList[0]) {
                        case "add":
                            add(filename, cmdList[1]);
                            break;
                        case "del":
                            del(filename);
                            break;
                        case "show":
                            show(filename);
                            break;
                        default:
                            System.out.println("Wrong Command!");
                    }
                }else{
                    System.out.println("No Colon!");
                }
            }
        }while(!isStop);

    }
    private static void add(String filename,String line) {
        FileWriter fw = null;

        try {
            fw = new FileWriter(filename,true);
            fw.write(line+"\n");
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private static void del(String filename) {
        System.out.println("Del "+filename);
    }
    private static void show(String filename) {

        ArrayList<String> list = readCSV(filename);

        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }

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
