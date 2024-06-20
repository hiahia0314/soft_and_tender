package file05;


import java.io.*;
import java.util.ArrayList;
//add:zhang,zhang,67890
//show:
//del:Ling
//done
public class CSVFile {
    public static void main(String[] args){
        ArrayList<String> list = readCSV("salary.csv");
        System.out.println(list+System.lineSeparator());

        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }
    }
    public static ArrayList<String> readCSV(String filename){
        ArrayList<String> a = new ArrayList<String>();
        //BufferedReader in=new BufferedReader(new InputStreamReader(System.in));

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
}
