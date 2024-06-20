package encapsulation09;

public class PositionB {
    double latitude;
    double longitude;

    public static double calculateDistance(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));

    }
    public static double calculateDirection(double x1, double y1, double x2, double y2){
        return Math.atan2(y2-y1,x2-x1);
    }

    public static void main(String[] args){
        double d = calculateDistance(111,35,108,36);
        double h = calculateDirection(111,35,108,36);
    }
}