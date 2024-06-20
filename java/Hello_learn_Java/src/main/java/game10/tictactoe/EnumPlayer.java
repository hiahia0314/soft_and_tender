package game10.tictactoe;

public class EnumPlayer {
    public static void main(String[] args){
        for (Result r: Result.values()) {
            System.out.println("name:"+r.name()+" ordinal:"+r.ordinal());
        }

        Result r = Result.GAMING;
        switch (r){
            case X_WIN: break;
            case O_WIN: break;
            case DRAW: break;
            case GAMING: break;

        }
    }
}
