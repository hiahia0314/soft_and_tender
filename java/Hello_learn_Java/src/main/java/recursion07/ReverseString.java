package recursion07;

public class ReverseString {

    public static void main(String [] args){
        String s = "abcde";

        String ss = reverse(s);

        System.out.println(ss);

    }
    public static int bin2dec(String s){
        int dec = 0;

        String rs = reverse(s);

        char[] array = rs.toCharArray();

        for(int i =0;i<array.length;i++)
            if(array[i]=='1')
                dec+= Math.pow(2,i);

        return dec;

    }
    public static String reverse(String s){
//        char[] sourceArray = s.toCharArray();
//        char[] targetArray = new char[sourceArray.length];
//
//        for (int i =0; i<sourceArray.length;i++) {
//
//            targetArray[sourceArray.length-i-1]=sourceArray[i];
//
//        }
//
//
//        return new String(targetArray);

        String head = "";
        String tail = "";

        head = s.substring(0,1);
        tail = s.substring(1);

        if(s.length()==1)
            return s;
        else return reverse(tail)+head;

    }
}
