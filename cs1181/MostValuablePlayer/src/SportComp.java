import java.util.Comparator;

/**
 * Class that implements Comparator of the type Athlete to sort
 * the athlete objects by sport then name.
 * 
 * @author Hannah Wysong
 */
public class SportComp implements Comparator<Athlete> {

    /**
     * Abstract method of the comparator class of tupe athlete. Compares
     * values of the Athletes sport, name, and rank.
     * 
     * @param Athlete a object being compared
     * @param Athlete b object that is compared to
     * @returns int result of comparison
     */
    public int compare(Athlete a, Athlete b) {
        // records result of comparing the sport of a to b
        int sports = a.getSport().compareTo(b.getSport());
        // returns result if value is not equal to 0
        if (sports != 0) {
            return sports;
        } else {
            // records result of comparing the name of a to b
            int names = a.getName().compareTo(b.getName());
            // returns result if value is not equal to 0
            if (names != 0) {
                return names;
            }
        }
        // returns result of the rank if the result of both comparisons is 0
        return a.getRanking().compareTo(b.getRanking());
    }

}
