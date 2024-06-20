package file05;

import java.io.*;

public class InputOutput {
    public static void dump(InputStream src, OutputStream dest) throws IOException{
        try(InputStream input =src;OutputStream output = dest){
            byte[] data = new byte[1024];
            int length;
            while((length=input.read(data))!=-1){
                output.write(data,0,length);
            }
        }

    }
    public static void dump2(Reader src, Writer dest) throws IOException{
        try(Reader input =src;Writer output = dest){
            char[] data = new char[1024];
            int length;
            while((length=input.read(data))!=-1){
                output.write(data,0,length);
            }
        }

    }

    public static void main(String[] args){
        try {
            //dump(new FileInputStream(args[0]),new FileOutputStream(args[1]));
//
////            URL url = new URL(args[0]);
////            dump(url.openStream(),new FileOutputStream(args[1]));

                dump2(new FileReader(args[0]),new FileWriter(args[1]));
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
