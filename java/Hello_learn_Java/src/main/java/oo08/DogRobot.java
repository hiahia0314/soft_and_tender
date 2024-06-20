package oo08;

public class DogRobot extends Robot implements Pet, Movable {

    public void play() {
        System.out.println("oo.DogRobot play");
    }

    @Override
    public void move() {
        System.out.println("oo.DogRobot move");
    }

    public static void main(String[] args){
        Pet[] pets = new Pet[2];

        pets[0] = new Dog();
        pets[1] = new DogRobot();

        for(Pet p : pets)
            p.play();
    }
}
