package gui11;

public class JavaNote11 {
    public void tortoiseHareRace(){
        boolean[] flags = {true, false};
        int totalStep =10;
        int tortoiseStep =0;
        int hareStep = 0;

        System.out.println("Start");

        while(tortoiseStep<totalStep && hareStep<totalStep){

            tortoiseStep++;
            System.out.printf("Tortoise ran %d steps.%n",tortoiseStep);

            boolean isHareSleep = flags[((int)(Math.random()*10))%2];
            if(isHareSleep){
                System.out.println("Hare is sleeping");
            }else {
                hareStep+=2;
                System.out.printf("Hare ran %d steps.%n",hareStep);
            }
        }
    }

    public void tortoiseHareRace2(){

        Tortoise tortoise = new Tortoise(10);
        Hare hare = new Hare(10);

        Thread tortoiseThread = new Thread(tortoise);
        Thread hareThread = new  Thread(hare);

        tortoiseThread.start();
        hareThread.start();

    }

    public static void main(String[]  args){
        JavaNote11 javaNote11 = new JavaNote11();
        //javaNote11.tortoiseHareRace2();

        Thread thread = new Thread(){
            public void run(){
                while(true){
                    System.out.println("this thread is daemon thread or not: "+isDaemon());
                    System.out.println("Orz");
                }
            }
        };
        thread.setDaemon(true);

        thread.start();
    }

    class Tortoise implements Runnable{
        private int totalStep;
        private int step;

        public Tortoise(int totalStep){
            this.totalStep = totalStep;
        }

        public void run(){
            while(step<totalStep){
                step++;
                System.out.printf("Tortoise ran %d steps.%n",step);
            }
        }
    }

    class Hare implements Runnable{
        private  boolean[] flags = {true,false};
        private int totalStep;
        private int step;

        public Hare(int totalStep){
            this.totalStep = totalStep;
        }

        public void run(){

            while(step<totalStep) {
                boolean isHareSleep = flags[((int) (Math.random() * 10)) % 2];
                if (isHareSleep) {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println("Hare is sleeping");
                } else {
                    step += 2;
                    System.out.printf("Hare ran %d steps.%n", step);
                }
            }
        }
    }
}
