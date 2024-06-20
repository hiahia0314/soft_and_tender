package variable_method02;

public class StaticMethods {

    static int amount;

    public StaticMethods(int amount){
        this.amount = amount;
    }
    public static void  eat(){
        System.out.println("variable02.Dog eat "+amount+" bones.");
    }
    public static void main(String[] args){
        eat();
        StaticMethods staticMethods = new StaticMethods(2);
        eat();
    }
}
