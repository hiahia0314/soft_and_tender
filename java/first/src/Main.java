import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        int one = 0;
        String temp=null;
        try {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            System.out.println("please enter a integer" );
            temp = br.readLine();
            one=Integer.parseInt(temp);
        }catch (IOException e){
            e.printStackTrace();
        }
        System.out.printf("Hello and welcome!"+one);
        ArrayList<String> a=new ArrayList<>();
        a=readfile.readCSV("csv.text");
        System.out.println(a);

    }
}
