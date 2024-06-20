package loop04;

public class Loop {


    public static void main(String[] args){

        int number = 7;
        double c =number*1.0/3;
        //a+=number;//a = a+number
        System.out.printf("%f%n",c);

        int remain = number%2;

        if(remain==0) {
            System.out.println("Even number!");
        }
        else {
            if(true)
                System.out.println("Odd number!");
            else {

            }
        }

        System.out.println(getGrade(90));

        for(int i=0;i<10;i++)
            System.out.print(i+"\n");

        for(int i =1;i<=9;i++){
            for(int j =1; j<=i;j++)
            {
                System.out.printf("%d*%d=%2d ",i,j,i*j);
            }
            System.out.println();
        }

        while(true){
            int n = (int) (Math.random()*10);
            System.out.println(n);
            if(n ==5){
                System.out.println("I hit 5");
                break;
            }
        }

        int n=0;
        while((n = (int) (Math.random()*10))!=5){
            System.out.println(n);
        }
        System.out.println("I hit 5");

        do{
            n = (int) (Math.random()*10);
            System.out.println(n);
        }while(n!=5);
        System.out.println("I hit 5");

        for(int i =1;i<10;i++){
            if(i==5){
                continue;
            }
            System.out.println(i);
        }
        for(int i =1;i<10;i++){
            if(i==5){
                break;
            }
            System.out.println(i);
        }

        System.out.println("GCD is "+gcd(1000,495));


    }
    public static int gcd(int m, int n){

        if(m%n ==0) return n;
        else return gcd(n,m%n);

    }

    //    public static int gcd(int m, int n){
//        int temp;
//        if(m<n){
//            temp = m;
//            m = n;
//            n = temp;
//        }
//        while (m % n!=0){
//            temp = m;
//            m = n;
//            n = temp % n;
//        }
//        return n;
//    }
    public static char getGrade(int score){
        //>=90 'A'
        //<90&&>=80 'B'
        //>=70 'C'
        //>=60 'D'
        //<60 'F'
        char c=' ';
        int q = score/10;
        switch (q){
            case 10:
            case 9: c ='A';break;
            case 8: c ='B';break;
            case 7: c ='C';break;
            case 6: c ='D';break;
            default: c ='F';break;
        }

        return c;
//        if(score<=100&&score>=90) {
//            return 'A';
//        }
//        else if(score>=80)
//            return 'B';
//        else if(score>=70)
//            return 'C';
//        else if(score>=60)
//            return 'D';
//        else if(score>=0)
//            return 'F';
//        else
//            return 'X';//Error
    }
}
