/**
 * Custom exception class
 * 
 * @author Hannah Wysong
 */
public class NegativeLengthException extends ExceptionInInitializerError{
    /**
     * Custom exception that prints the error message when thrown
     * 
     * @param errorMessage Error being thrown
     */
    public NegativeLengthException(String errorMessage){
        super(errorMessage);
    }
}
