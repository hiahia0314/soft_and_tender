package variable_method02;


public class Variable {
    public static double d;

    public static void main(String[] args){
        double dd=0.0d;
        String s="您好！";

        System.out.printf("%d  %d\n",Integer.MIN_VALUE,Integer.MAX_VALUE);
        System.out.printf("%e  %e\n",Float.MIN_VALUE,Float.MAX_VALUE);
        System.out.printf("%e  %e\n",Double.MIN_VALUE,Double.MAX_VALUE);
        System.out.printf("%10d  %d\n",12345,67890);
        System.out.printf("%10d  %d\n",12345678,67890);
        System.out.printf("%.2e  %.3e\n",1.2358,6.789);
        System.out.printf("%.2f  %.3f\n",1.2358,6.789);
        System.out.printf("%2.2f  %2.3f\n",12.358,6.789);

        System.out.println(s+"\u0048\u0065\u006C\u006C\u006F");

        System.out.println((2+2*4)/3);
        System.out.printf("%b%n",(2+2*4)/3<3);
        int score=56;
        System.out.printf("%c%n",score>=60 || score<70?'是':'否');
        int number =1024;
        System.out.printf("%d%n",number>>9);
        System.out.printf("%d%n",number++);
        System.out.printf("%d%n",++number);

        int a =(int)123.546;
        //a+=number;//a = a+number
        System.out.printf("%d%n",a);

        int b =10/3;
        //a+=number;//a = a+number
        System.out.printf("%d%n",b);

        number = 7;
        double c =number*1.0/3;
        //a+=number;//a = a+number
        System.out.printf("%f%n",c);

        int remain = number%2;

        if(remain==0) {
            System.out.println("Even number!");
        }else if(true){
            System.out.println("Odd number!");
        }else{
            ;
        }
    }
}
