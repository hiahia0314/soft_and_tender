package encapsulation09;

public class PositionIII {
    private double phi;
    private double theta;
    private Geometry geometry;
    private Units units;

    public PositionIII(double latitude, double longitude){
        this.phi = latitude;
        this.theta = longitude;
        this.geometry = new Geometry();
        this.units = new Units();
    }

    public void setLatitude(double latitude){
        setPhi(Math.toRadians(latitude));
    }
    public void setLongitude(double longitude){
        setTheta(Math.toRadians(longitude));
    }
    public void setPhi(double phi){
        if(phi < -0.5*Math.PI)
            this.phi = -0.5*Math.PI;
        else if(phi > 0.5*Math.PI)
            this.phi = 0.5*Math.PI;
        else
            this.phi = phi;
    }

    public void setTheta(double theta){
        if(theta < -Math.PI)
            this.theta = -Math.PI;
        else if(theta > Math.PI)
            this.theta = Math.PI;
        else
            this.theta = theta;
    }
    public double getLatitude(){
        return Math.toDegrees(this.phi);
    }
    public double getLongitude(){
        return Math.toDegrees(this.theta);
    }
    public double getDistance(PositionIII p){
        return units.toKilos(geometry.getDistance(this.phi, this.theta, p.phi, p.theta));
    }
    public double getDirection(PositionIII p){
        return geometry.getDirection(this.phi, this.theta, p.phi, p.theta);
    }
    public static void main(String[] args){
        PositionIII p1 = new PositionIII(111,35);
        PositionIII p2 = new PositionIII(108,36);
        double d = p1.getDistance(p2);
        double h = p1.getDirection(p2);
    }

}
class Geometry{
    public double getDistance(double x1, double y1,double x2, double y2){
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }
    public double getDirection(double x1, double y1,double x2, double y2){
        return Math.atan2(y2-y1,x2-x1);
    }
}
class Units{
    public double toMiles(double d){
        return d*0.621371;
    }
    public double toKilos(double d){
        return d*1.60934;
    }
}
