import org.junit.Test;
import recursion07.ReverseString;

import static org.junit.Assert.assertEquals;

public class ReverseStringTest {

    @Test
    public void testReverse(){
        String s = ReverseString.reverse("abcde");

        assertEquals("edcba",s);
    }
    @Test
    public void testReverse2(){
        String s = ReverseString.reverse("asdfghjkl");

        assertEquals("lkjhgfdsa",s);
    }
    @Test
    public void testBin2Dec(){
        int d = ReverseString.bin2dec("110");

        assertEquals(6,d);
    }
    @Test
    public void testBin2Dec2(){
        int d = ReverseString.bin2dec("10110");

        assertEquals(22,d);
    }
}
