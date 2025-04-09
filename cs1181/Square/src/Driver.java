import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Driver class containing the main method
 * 
 * @author Hannah Wysong
 */
public class Driver {
    /**
     * Main method of code. Tests an input for exceptions. If the value entered
     * is negative, it throws a custom exception. If a non-double is entered, it 
     * cathes the InputMismatchException. After validating input, it creates a 
     * Square object and prints.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args){

        double sideLength = 0;
        boolean valid = true;
        Scanner scnr = new Scanner(System.in);

        while(valid){
        System.out.print("Enter the length of the square's sides: "); 
        try{
        sideLength = scnr.nextDouble();
        try{
            if(sideLength < 0){ 
                throw new NegativeLengthException("Negative length: " + sideLength);
            }
            else{
                valid = false;
            }
        }
        catch(NegativeLengthException e){
            System.out.println(e.getMessage());
        }
        }
        catch (InputMismatchException e){
            System.out.println("Error: you must enter a number");
            scnr.next();
        }
    }
        Square square = new Square(sideLength);
        System.out.println(square.toString());
        scnr.close();
    }
}