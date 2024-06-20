package encapsulation09;

public class PositionII{
    private double longitude;
    private double latitude;

    public PositionII(double longitude, double latitude){
        this.longitude = longitude;
        this.latitude = latitude;
    }
    public double getLongtitude(){
        return longitude;
    }
    public double getlatitude(){
        return latitude;
    }
    public void setLongtitude(double d){
        if(d < 0)
            longitude = 0;
        else if(d > 180)
            longitude = 180;
        else
            longitude = d;
    }
    public void setlatitude(double d){
        if(d < 0)
            latitude = 0;
        else if(d > 90)
            latitude = 90;
        else
            latitude = d;
    }

    public double distance(PositionII p){
        return 0.0;
    }
    public double direction(PositionII p){
        return 0.0;
    }

    public static void main(String[] args){
        PositionII p1 = new PositionII(111,35);
        PositionII p2 = new PositionII(108,36);


        double d = p1.distance(p2);
        double h = p1.direction(p2);
    }
}