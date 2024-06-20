package oo08;

public class Dog extends Animal implements Pet {


    public void sleep() {
        System.out.println("oo.Dog sleep");
    }

    public static void main(String[] args){
        Dog d2 = new Dog();
        d2.eat();
        d2.sleep();
    }

    public void play(){
        System.out.println("oo.Dog play");
    }
}
