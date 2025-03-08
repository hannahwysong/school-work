/**
 *  Truck_Start class that creates an event for when the trucks start . It keeps track of truck
 *  number and the time the truck starts.
 * 
 * @author Hannah Wysong
 */
public class Truck_Start extends Event {
    private static int truckNum = 0;

    /**
     * Method that inherits the Event class to create a Truck_Start event. 
     * 
     * @param time double time truck event starts
     * @param truckNum int truck number
     */
    public Truck_Start(double time) {
        super(time, truckNum++);
    }
}
