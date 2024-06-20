
public class Player {
    int number=0;
    public void guess(){
        number=(int) (Math.random()*20);
        System.out.println("l am guessing "+number);
    }
}
