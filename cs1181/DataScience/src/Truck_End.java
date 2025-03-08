/**
 *  Truck_End class that creates an event for when the trucks come to a stop. It keeps track of 
 *  truck number and the time the truck ends.
 * 
 * @author Hannah Wysong
 */
public class Truck_End extends Event {

    /**
     * Method that inherits the Event class to create a Truck_End event. 
     * 
     * @param time double time truck event ends
     * @param truckNum int truck number
     */
    public Truck_End(double time, int truckNum) {
        super(time, truckNum);
    }
}
