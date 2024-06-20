
import branch03.GPA;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class GPATest {
    @Test
    public void testGPA(){
        double gpa = GPA.calculateGPA(100,100,100);
        assertEquals(100.0,gpa);
    }
}
