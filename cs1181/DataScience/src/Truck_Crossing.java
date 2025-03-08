/**
 *  Truck_Crossing class that creates an event for when the trucks cross the crossing. It keeps track
 *  of truck number and the time the truck crosses.
 * 
 * @author Hannah Wysong
 */
public class Truck_Crossing extends Event {

    /**
     * Method that inherits the Event class to create a Truck_Crossing event. 
     * 
     * @param time double time truck event crosses
     * @param truckNum int truck number
     */
    public Truck_Crossing (double time, int truckNum) {
        super(time, truckNum);
    }
}
