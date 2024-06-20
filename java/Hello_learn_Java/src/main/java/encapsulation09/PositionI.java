package encapsulation09;

public class PositionI{
    public double longitude;
    public double latitude;


    public double distance(PositionI p){

        return 0.0;
    }
    public double direction(PositionI p){
        return 0.0;
    }

    public static void main(String[] args){
        PositionI p1 = new PositionI();
        p1.longitude = 111;
        p1.latitude = 35;

        PositionI p2 = new PositionI();
        p2.longitude = 108;
        p2.latitude = 36;


        double d = p1.distance(p2);
        double h = p1.direction(p2);
    }

}