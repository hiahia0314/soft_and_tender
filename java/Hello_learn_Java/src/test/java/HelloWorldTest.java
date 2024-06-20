

import main.java.helloworld01.HelloWorld;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class HelloWorldTest {

    @Test
    public void testJava() {

        int i = HelloWorld.add(100, 34);

        assertEquals(134, i);

    }

    public static class AddTest {
        @Test
        public void testAdd() {
            int i = HelloWorld.add(100, 34);

            assertEquals(134, i);
        }

    }
}
