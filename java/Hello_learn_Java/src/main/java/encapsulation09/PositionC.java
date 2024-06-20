package encapsulation09;

public class PositionC {
    double latitude;
    double longitude;

    public double getDistance(double x2, double y2){
        return Math.sqrt(Math.pow(x2 - latitude, 2) + Math.pow(y2 - longitude, 2));

    }
    public double getDirection(double x2, double y2){
        return Math.atan2(y2-longitude,x2-latitude);
    }

    public static void main(String[] args){
        PositionC p1 = new PositionC();
        p1.latitude = 111;
        p1.longitude = 35;
        double d = p1.getDistance(108,36);
        double h = p1.getDirection(108,36);
    }
}