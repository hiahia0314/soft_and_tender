package variable_method02;

import java.util.ArrayList;

public class Dog {
    public String name;
    public int age;
    public static int numOfDogs;

    public Dog(){
        name="Puppy";
        age=0;
        numOfDogs++;
    }
    public Dog(String s, int a){
        name=s;
        age=a;
        numOfDogs++;
    }

    public void bark(){

        if(age>=3) System.out.println(name+":WoWoWo!");
        else System.out.println(name+":Wo!");

    }

    public static void main(String[] args){
        Dog d1 = new Dog("oo.Teddy",3);
        Dog d2 = new Dog();
        Dog d3 = d1;
        Dog d4 = new Dog("oo.Teddy",3);

        System.out.println(d1.name);

        d3.bark();
        d2.bark();

        if(d1==d4) System.out.println("yes");
        else System.out.println("no");

        String s1 = new String("abc");
        String s2 = new String("abc");

        if(s1==s2) System.out.println("yes");
        else System.out.println("no");

        if(s1.equals(s2)) System.out.println("yes");
        else System.out.println("no");

        String s3 = "abc";
        String s4 = "abc";

        if(s3==s4) System.out.println("yes");
        else System.out.println("no");

        d2 = d1;
        //d2 = null;

        d2.bark();

        int i =100;
        Integer integer = new Integer(i);
        System.out.print(integer.intValue());

        ArrayList<Integer> scoresList = new ArrayList<Integer>();

        //java.lang.Object is  root class

    }
}