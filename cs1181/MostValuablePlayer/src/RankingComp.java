import java.util.Comparator;

/**
 * Class that implemts Comparator of the type athlete to sort the
 * athlete objects by sport then rank
 * 
 * @author Hannah Wysong
 */
public class RankingComp implements Comparator<Athlete> {
    /**
     * Abstract method of the comparator class of tupe athlete. Compares
     * values of the Athletes sport, name, and rank.
     * 
     * @param Athlete a object being compared
     * @param Athlete b object that is compared to
     * @returns int result of comparison
     */
    public int compare(Athlete a, Athlete b) {
        // compares sports by alphabetical order
        int sport = a.getSport().compareTo(b.getSport());
        // retuns value of comparison if sports are not identical
        if (sport != 0) {
            return sport;
        } else {
            // compares ranking by value
            // ranking is organized from least to greatest
            int ranking = a.getRanking().compareTo(b.getRanking());
            // returns value of comparison if ranks are not equal
            if (ranking != 0) {
                return ranking;
            }
            // returns value of name comparison if sport and rank are both equal
            return a.getName().compareTo(b.getName());
        }
    }
}
