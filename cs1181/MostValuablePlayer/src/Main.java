import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Main class of Athlete object.
 * 
 * @author Hannah Wysong
 */
public class Main<E> {
    /**
     * Main method that Creates a list of Athletes and prints the unsorted
     * list, a list sorted by sport then name, and a list sorted by
     * sport then rank.
     * 
     * @param args Command line arguments
     */
    public static void main(String[] args) {
        // creates an empty list of athletes
        List<Athlete<Integer>> unsortedList = new ArrayList<>();
        // creates athlete objects of the type integer and adds them to list
        Athlete<Integer> a1 = new Athlete<Integer>("Adam Scott", "Football", 4);
        unsortedList.add(a1);
        Athlete<Integer> a2 = new Athlete<Integer>("Rachel Reeves", "Tennis", 6);
        unsortedList.add(a2);
        Athlete<Integer> a3 = new Athlete<Integer>("Adam Scott", "Volleyball", 2);
        unsortedList.add(a3);
        Athlete<Integer> a4 = new Athlete<Integer>("Micheal Reeves", "Football", 2);
        unsortedList.add(a4);
        Athlete<Integer> a5 = new Athlete<Integer>("George McMann", "Basketball", 4);
        unsortedList.add(a5);

        // prints the unsorted list
        System.out.println("Unsorted");
        for (Athlete i : unsortedList) {
            System.out.println(i.toString());
        }
        System.out.println("");

        // sorts the list by sport then name
        Collections.sort(unsortedList, new SportComp());
        // prints the sorted list
        System.out.println("Sorted by sport then name");
        for (Athlete i : unsortedList) {
            System.out.println(i.toString());
        }
        System.out.println("");

        // sorts the list by sport then rank
        Collections.sort(unsortedList, new RankingComp());
        // prints the sorted list
        System.out.println("Sorted by sport then ranking");
        for (Athlete i : unsortedList) {
            System.out.println(i.toString());
        }
    }
}
