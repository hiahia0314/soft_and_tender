package game10.pingpong;

public class Agent {

    int hitRate;

    public Agent(int rate){
        hitRate = rate;
    }


    public String serve(){
        int i = (int)(Math.random()*100);
        if(i%2==1)
            return "L";
        else
            return "R";
    }

    public String receive(String hitP){
        String result = "";
        int i = (int)(Math.random()*100);
        if(i<hitRate)
            result = hitP;
        else {

            if(hitP.equals("L"))
                result="R";
            else if(hitP.equals("R"))
                result="L";
        }
        return result;
    }
}
