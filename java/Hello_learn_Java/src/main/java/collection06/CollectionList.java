package collection06;

import java.util.*;

public class CollectionList {
    public ArrayList<String> stringArrayList = new ArrayList<>();
    public LinkedList<String> stringLinkedList = new LinkedList<>();

    public static void main(String[] args){
        CollectionList jn9 = new CollectionList();

        jn9.stringArrayList.add("one");
        jn9.stringArrayList.add("two");
        jn9.stringArrayList.add(1,"three");


        jn9.stringLinkedList.add("four");
        jn9.stringLinkedList.add("five");
        jn9.stringLinkedList.add(1,"six");

        for(int i = 0; i<jn9.stringArrayList.size(); i++) {
            System.out.println(jn9.stringArrayList.get(i));
        }

        for(int i = 0; i<jn9.stringArrayList.size(); i++) {
            System.out.println(jn9.stringLinkedList.get(i));
        }

        Scanner console = new Scanner(System.in);

        System.out.println("Please input a sentence:");
        Set words = tokenSet(console.nextLine());
        System.out.printf("There are %d words,%s%n",words.size(),words);

        words.add("pig");

        System.out.printf("There are %d words,%s%n",words.size(),words);

        Queue<String> stringQueue = jn9.stringLinkedList;

        stringQueue.offer("seven");
        stringQueue.offer("eight");
        stringQueue.offer("nine");

        System.out.println(stringQueue.size());

        while(stringQueue.peek()!=null){
            System.out.println(stringQueue.poll());
        }
        System.out.println(stringQueue.size());



    }

    static  Set tokenSet(String line){
        String[] tokens = line.split(" ");

        for(String s : tokens)
            System.out.println(s);

        return new HashSet(Arrays.asList(tokens));
    }
}
