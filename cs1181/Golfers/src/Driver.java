import java.util.ArrayList;
import java.util.Collections;

/**
 * Driver class that contains the main method. Also sorts
 * the objects into an arrayList.
 * 
 * @Author Hannah Wysong 
 */

public class Driver {

    public static ArrayList<Golfer> golferList = new ArrayList<Golfer>();

    /**
     * The main method. Creates 3 golfer objects, and adds them to
     * an arrayList. The arrayList is sorted by score, and alphabetically
     * it prints the result.
     * 
     * @param String args The command line arguments
     */
    public static void main(String[] args){
        Golfer golfer1 = new Golfer("Sam", "Wazoski", -10,19);
        golferList.add(golfer1);
        Golfer golfer2 = new Golfer("Sam", "Smith", -13,21);
        golferList.add(golfer2);
        Golfer golfer3 = new Golfer("Carol", "Smith", -13, 19);
        golferList.add(golfer3);

        Collections.sort(golferList);
            for (Golfer g: golferList){
                System.out.print(g + ", ");
            }
    }
}
