package oo08;

import variable_method02.Dog;

public class Teddy extends Dog {
    public void bark(){ // Overriding, Same Method,
        System.out.println("oo.Teddy Bark!");
    }
    public void play(){
        System.out.println("oo.Teddy Play!");
    }
    public static void main(String[] args){
        Teddy t = new Teddy();
        //System.out.print(t.name);

        t.bark();
        t.play();

        Dog d = t;
        d.bark();
        //d.play();


        System.out.print("---------------\n");
        //Initialization
        Dog[] dlist  = new Dog[2];
        dlist[0] = new Teddy();
        dlist[1] = new Husky();

        //Client
        for(Dog dd : dlist) {
            dd.bark();
        }


        feed(new Teddy());
        feed(new Husky());

    }
    public static void feed(Dog d){
        System.out.println(d.name+"feed");
    }
}
