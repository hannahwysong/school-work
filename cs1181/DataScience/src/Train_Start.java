/**
 *  Train_Start class that creates an event for when the train starts. It keeps track of 
 *  the time the train starts.
 * 
 * @author Hannah Wysong
 */
public class Train_Start extends Event{
    /**
     * Method that inherits the Event class to create a train_start event. 
     * 
     * @param time double time train event starts
     */
    public Train_Start(double time) {
        super(time);
    }
}
