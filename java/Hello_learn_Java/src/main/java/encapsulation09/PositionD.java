package encapsulation09;

public class PositionD
{
    double x1,x2,y1,y2;

    public double calculateDistance(){
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }
    public double calculateDirection(){
        return Math.atan2(y2-y1,x2-x1);
    }
    public static void main(String[] args){
        PositionD p1 = new PositionD();
        p1.x1 = 111;
        p1.y1 = 35;
        p1.x2 = 108;
        p1.y2 = 36;
        double d = p1.calculateDistance();
        double h = p1.calculateDirection();
    }
}