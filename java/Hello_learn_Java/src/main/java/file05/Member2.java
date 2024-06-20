package file05;

import java.io.*;

public class Member2 {
    private String number;
    private String name;
    private int age;

    public Member2(String number, String name, int age){
        this.number = number;
        this.name = name;
        this.age = age;

    }

    public String toString(){
        return String.format("(%s,%s,%d)",number,name,age);

    }

    public void save()throws IOException{
        try(ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(number))){
            output.writeObject(this);
        }
    }
    public static Member2 load(String number) throws IOException,ClassNotFoundException{
        Member2 member;
        try(ObjectInputStream input = new ObjectInputStream(new FileInputStream(number))){
            member = (Member2) input.readObject();
        }
        return member;
    }
    public static void main(String[] args){
        Member[] members = { new Member("B1234","Justin",90),
                new Member("B5678","Monica",95),
                new Member("B9876","Irene",88)};
        for(Member member:members){
            try {
                member.save();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        try {
            System.out.println(Member.load("B1234"));
            System.out.println(Member.load("B5678"));
            System.out.println(Member.load("B9876"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
