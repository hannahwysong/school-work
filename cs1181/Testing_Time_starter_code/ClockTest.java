import static org.junit.Assert.assertEquals;

import org.junit.Test;

/**
 * Class containing test methods for the clock method getEarlier()
 * 
 * @author Hannah Wysong
 */
public class ClockTest {

    /**
     * Test method for getEarlier(), tests to check if the
     * correct meridian is returned. Returns clock object
     * containing a.m
     */
    @Test
    public void testAMvPM(){

        Clock AM = new Clock(5,20,"a.m.");
        Clock PM = new Clock(6,40,"p.m.");
        Clock result = Clock.getEarlier(AM, PM);
        assertEquals(AM, result);

    }

    /**
     * Test method for getEarlier(), tests to check if the
     * correct meridian is returned. Returns clock object
     * containg a.m.
     */
    @Test
    public void testPMvAM(){

        Clock AM = new Clock(7,20,"a.m.");
        Clock PM = new Clock(9,30,"p.m.");
        Clock result = Clock.getEarlier(PM, AM);
        assertEquals(AM, result);
         
    }
    
    /**
     * Test method for getEarlier(), tests to check if 
     * clock object has 12 in the hours element.
     */
    @Test
    public void testIf12AM(){

        Clock c1 = new Clock(12,20,"a.m.");
        Clock c2 = new Clock(9,30,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c1, result);
         
    }

    /**
     * Test method for getEarlier(), tests to check if 
     * clock object has 12 in the hours element.
     */
    @Test
    public void testIf12PM(){

        Clock c1 = new Clock(7,20,"a.m.");
        Clock c2 = new Clock(12,30,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c2, result);
         
    }

    /**
     * Test method for getEarlier(), tests to check which
     * clock object has less hours. Returns the clock object
     * with less.
     */
    @Test
    public void testifLessHours(){

        Clock c1 = new Clock(7,30,"a.m.");
        Clock c2 = new Clock(9,30,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c1, result);
         
    }

     /**
     * Test method for getEarlier(), tests to check which
     * clock object has less hours. Returns the clock object
     * with less.
     */
    @Test
    public void testifLessHours2(){

        Clock c1 = new Clock(7,30,"a.m.");
        Clock c2 = new Clock(5,30,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c2, result);
         
    }

    /**
     * Test method for getEarlier(), tests to check which
     * clock object has less minutes. Returns the clock object
     * with less.
     */
    @Test
    public void testIfLessMinutes(){

        Clock c1 = new Clock(7,0,"a.m.");
        Clock c2 = new Clock(7,30,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c1, result);
         
    }

    /**
     * Test method for getEarlier(), tests to check which
     * clock object has less minutes. Returns the clock object
     * with less.
     */
    @Test
    public void testifLessrMinutes2(){

        Clock c1 = new Clock(7,30,"a.m.");
        Clock c2 = new Clock(7,0,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c2, result);
         
    }

    /**
     * Test method for getEarlier(), checks to see if both
     * clock objects have the same elements. Returns the 
     * first object if the same.
     */
    @Test
    public void testSameTime(){

        Clock c1 = new Clock(7,20,"a.m.");
        Clock c2 = new Clock(7,20,"a.m.");
        Clock result = Clock.getEarlier(c1, c2);
        assertEquals(c1, result);
         
    }
}
