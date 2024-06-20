package game10.pingpong;

public class Player {
    public String serve(){
        int i = (int)(Math.random()*10);
        if(i%2==1)
            return "L";
        else
            return "R";
    }

}
