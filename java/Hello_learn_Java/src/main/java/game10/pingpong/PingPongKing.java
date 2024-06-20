package game10.pingpong;

public class PingPongKing {
    ClassicGame game = new ClassicGame();

    public void start(){

        game.run();

    }
    public static void main(String [] args){
        PingPongKing pingPongKing = new PingPongKing();
        pingPongKing.start();
    }
}
