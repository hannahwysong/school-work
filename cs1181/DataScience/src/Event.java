/**
 * Event class implementing comparable. Indicates that an event has occured.
 * 
 * @author Hannah wysong
 */
public class Event implements Comparable<Event> {

    private double time;
    private int truckNum; // optional used to track trucks

    /**
     * Constructor class for events only containing time 
     * 
     * @param time double time the event occurs
     */
    public Event(double time) {
        this.time = time;
    }

    // truck num constructor
    /**
     * Constructor class for events containing time and truck number
     * 
     * @param time double time the event occurs
     * @param truckNum int truck number
     */
    public Event(double time, int truckNum) {
        this.time = time;
        this.truckNum = truckNum;
    }

    /**
     * Getter method for event time
     * 
     * @return time double time of event
     */
    public double getTime() {
        return time;
    }

    /**
     * Getter method for event truck number
     * 
     * @return int truck number
     */
    public int getTruckNum() {
        return truckNum;
    }

    /**
     * Abstract method for comparable interface. Compares by time, then trucks over trains
     * 
     * @param Event other Event being compared 
     * @return int result of comparison 
     */
    public int compareTo(Event other) {

        // sort by time
        if (this.time < other.time) {
            return -1;
        } else if (this.time > other.time) {
            return 1;
        }
        // events have same time
        else {
            // trucks crossing take priority over trains
            if (this instanceof Truck_At_Crossing && other instanceof Truck_Crossing) {
                return -1; 
            } else if (this instanceof Train_Start || this instanceof Train_End) {
                return -1;
            } else {
                return 1;
            }
        }
        }
    }

