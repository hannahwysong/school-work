import java.util.ArrayList;

import net.lingala.zip4j.core.*;
import net.lingala.zip4j.exception.*;

/**
 * MultiThread custom thread class used to check if the password is correct
 * to unlock a zip file.
 * 
 * @author Hannah Wysong
 */
public class MultiThread extends Thread {

    private int start; // beginning of thread work
    private int end; // end of thread work
    private ArrayList<String> combinations; // potential passwords
    private String fileName; // zipped file name
    private volatile boolean isCracked = false; // if password is found or not
    private long time; // program start time
    
/**
 * Constructor class for MultiThread object. Assigns each thread a start and an end position, an
 * arraylist to pull from, the filename being cracked, and the time the program began
 * 
 * @param start beginning position of thread in array
 * @param end end position of thread in array
 * @param combinations arraylist of potential passwords being pulled from
 * @param fileName filename of zipped file being cracked
 * @param time time the program began
 */
    public MultiThread(int start, int end,ArrayList<String> combinations, String fileName, long time) {
        this.start = start;
        this.end = end;
        this.fileName = fileName;
        this.combinations = combinations; 
        this.time = time;
    }


    /**
     * Override of the Run method for Thread. Tells the thread to run through the list of potential 
     * passwords in its range and test the password. If the password is correct it is printed along
     * with the program duration. Otherwise it continues to loop until the password is found.
     */
    @Override
    public void run() {
        for (int i = start; i < end; i++) { // iterates through list from begining to end
            if (isCracked) { // checks if password has been found
                return; // returns to driver
            }
        try {
            ZipFile zipFile = new ZipFile(fileName); // creates new zip file
            zipFile.setPassword(combinations.get(i)); // tests passwords 
            zipFile.extractAll("contents"); // checks for message
            System.out.println("Correct Password " + combinations.get(i)); // prints password if found

            long end = System.currentTimeMillis(); // records program end time
            System.out.println("Finished in " + (end - time) + " ms"); // prints program duration
            System.exit(0); // closes the program
        } catch (ZipException ze) { // handles incorrect passwords
            System.out.println("Incorrect Password");
        }
    }
    }
}
