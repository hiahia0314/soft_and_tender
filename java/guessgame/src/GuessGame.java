public class GuessGame {
    Player p1;
    Player p2;
    Player p3;
    public void startGame(){
        p1=new Player();
        p2=new Player();
        p3=new Player();
        int guessp1=0;
        int guessp2=0;
        int guessp3=0;
        boolean p1isright=false;
        boolean p2isright=false;
        boolean p3isright=false;
        int targetNumber=(int) (Math.random()*20);
        System.out.println("the target is"+targetNumber);
        while (true){
            p1.guess();
            p2.guess();
            p3.guess();

            guessp1=p1.number;
            guessp2=p2.number;
            guessp3=p3.number;

            System.out.println("p1.guess is "+guessp1);
            System.out.println("p2.guess is "+guessp2);
            System.out.println("p3.guess is "+guessp3);

            if(guessp1==targetNumber){
                p1isright=true;
            }
            if(guessp2==targetNumber){
                p2isright=true;
            }
            if(guessp3==targetNumber){
                p3isright=true;
            }
            if(p2isright==true||p1isright==true||p3isright==true){
                System.out.println("game is over");
                System.out.println("p1 "+p1isright);
                System.out.println("p2 "+p2isright);
                System.out.println("p3 "+p3isright);
                break;
            }else {
                System.out.println("NO winner");
            }
        }

    }
}
