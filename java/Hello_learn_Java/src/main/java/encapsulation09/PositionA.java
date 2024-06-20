package encapsulation09;

public class PositionA {
    public double latitude;
    public double longitude;
}
class PositionUtility{
    public static double distance(PositionA position1, PositionA position2){
        //Calculate and return the distance between the specified positions.
        return 0.0;
    }
    public static double heading(PositionA position1, PositionA position2){
        //Calculate and return the heading from position1 to position2
        return 0.0;
    }
    public static void main(String[] args){
        PositionA p1 = new PositionA();
        p1.latitude = 111;
        p1.longitude = 35;
        PositionA p2 = new PositionA();
        p2.latitude = 108;
        p2.longitude = 36;
        double d = PositionUtility.distance(p1,p2);
        double h = PositionUtility.heading(p1,p2);
    }
}