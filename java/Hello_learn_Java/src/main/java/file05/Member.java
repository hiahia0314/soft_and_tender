package file05;

import java.io.*;

public class Member {
    private String number;
    private String name;
    private int age;

    public Member(String number, String name, int age){
        this.number = number;
        this.name = name;
        this.age = age;

    }

    public String toString(){
        return String.format("(%s,%s,%d)",number,name,age);

    }

    public void save()throws IOException{
        try(DataOutputStream output = new DataOutputStream(new FileOutputStream(number))){
            output.writeUTF(number);
            output.writeUTF(name);
            output.writeInt(age);
        }
    }
    public static Member load(String number) throws IOException{
        Member member;
        try(DataInputStream input = new DataInputStream(new FileInputStream(number))){
            member = new Member(input.readUTF(),input.readUTF(),input.readInt());
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
