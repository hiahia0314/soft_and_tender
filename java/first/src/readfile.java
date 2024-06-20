import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class readfile {

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

}
