/**
 * The Clock class that creates a clock object and assigns
 * hours minutes and meridian. 
 */
public class Clock {

    
    private int hours;
    private int minutes;
    private String meridian;

    /**
     * Empty Clock constructor class 
     */
    public Clock() {}

    /**
     * Constructor class for the Clock object.
     * 
     * @param hours Hours on the clock
     * @param minutes Minutes on the clock
     * @param meridian A.M. or P.M.
     */
    public Clock(int hours, int minutes, String meridian) {
        this.hours = hours;
        this.minutes = minutes;
        this.meridian = meridian;
    }

    /**
     * Override of toString method. Returns a string of the form
     * hours:minutes meridian.
     * 
     * @return String 
     */
    @Override
    public String toString() {
        String time = hours + ":";
        if (minutes < 10) {
            time += "0";
        }
        time += minutes + " " + meridian;
        return time;
    }

    /**
     * Tests both of the clock object elements to compare and returns
     * the correct clock object.
     * 
     * @param c1 clock object 
     * @param c2 clock object
     * @return Clock either of the original clock objects 
     */
    public static Clock getEarlier(Clock c1, Clock c2) {
        if (c1.meridian.equals("a.m.") && c2.meridian.equals("p.m.")) {
            return c1;
        } else if (c1.meridian.equals("p.m.") && c2.meridian.equals("a.m.")) {
            return c2;
        } else {
            // there is a special case if it is 12-something a.m. or p.m. on one
            // but not both of the clocks (i.e. 12:00 a.m. is before 1:00 a.m.)
            if (c1.hours == 12 && c2.hours != 12) {
                return c1;
            } else if (c2.hours == 12 && c1.hours != 12) {
                return c2;
            } else {
                if (c1.hours < c2.hours) {
                    return c1;
                } else if (c2.hours < c1.hours) {
                    return c2;
                } else {
                    if (c1.minutes < c2.minutes) {
                        return c1;
                    } else if (c2.minutes < c1.minutes) {
                        return c2;
                    } else {
                        // the clocks have the same time
                        assert c1.toString().equals(c2.toString()) : c1.toString() + " " + c2.toString();
                        // we will arbitrarily return the first one
                        return c1;
                    }
                }
            }
        }
    }
}