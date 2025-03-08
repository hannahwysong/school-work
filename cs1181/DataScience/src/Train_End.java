/**
 *  Train_End class that creates an event for when the train comes to a stop. It keeps track of 
 *  the time the train ends.
 * 
 * @author Hannah Wysong
 */
public class Train_End extends Event {
    /**
     * Method that inherits the Event class to create a train_end event. 
     * 
     * @param time double time train event ends
     */
    public Train_End(double time) {
        super(time);
    }
}
