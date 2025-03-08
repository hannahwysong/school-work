/**
 *  Truck_At_Crossing class that creates an event for when the trucks are at the crossing. It keeps track of 
 *  truck number and the time the truck starts.
 * 
 * @author Hannah Wysong
 */
public class Truck_At_Crossing extends Event {

    /**
     * Method that inherits the Event class to create a Truck_At_Crossing event. 
     * 
     * @param time double time truck at crossing event starts
     * @param truckNum int truck number
     */
    public Truck_At_Crossing(double time, int truckNum) {
        super(time, truckNum);
    }
}
