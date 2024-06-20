package game10.pingpong;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Set {

    Player p = new Player();
    Agent a = new Agent(50);


    public String playOneSet(){
        boolean isOver =false;
        String result = "";
        System.out.println("========================");
        do{
            String hitA = a.serve();
            System.out.println("------------------------");
            System.out.println("A Serve:"+hitA);
            String hitP = inputString("Hit Left(L) or Right(R)?");

            if(!hitP.equals(hitA)){
                result = "A";
                isOver = true;
            }
            else{
                hitP=p.serve();
                System.out.println("------------------------");
                System.out.println("P Serve:"+hitP);
                hitA=a.receive(hitP);
                System.out.println("A Receive:"+hitA);

                if(!hitA.equals(hitP)) {
                    result = "P";
                    isOver = true;
                }
            }

        }while(!isOver);



        return result;
    }



    public String inputString(String prompt) {
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
