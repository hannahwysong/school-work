/**
 * Class for generic Athlete object. Initalizes the object with a name,
 * sport, and a ranking. Overrides compareTo and toString mehtods.
 * 
 * @author Hannah Wysong
 */
public class Athlete<E extends Comparable<E>> implements Comparable<Athlete<E>> {

    // global objects
    private String name;
    private String sport;
    private E ranking;

    /**
     * Constructor class for Athlete object
     *
     * @param name    String name of Athlete
     * @param sport   String sport Athlete plays
     * @param ranking E rank of Athlete
     */
    public Athlete(String name, String sport, E ranking) {
        // initalizes elements
        this.name = name;
        this.sport = sport;
        this.ranking = ranking;
    }

    /**
     * Getter method for the Althlete's name
     * 
     * @return String name of athlete
     */
    public String getName() {
        return this.name;
    }

    /**
     * Getter method for Athlete's sport
     * 
     * @return String sport athlete plays
     */
    public String getSport() {
        return this.sport;
    }

    /**
     * Getter method for the Athlete' ranking
     * 
     * @return E rank of athlete
     */
    public E getRanking() {
        return this.ranking;
    }

    /**
     * Ovveride of compareTo method. Used by Comparator classes
     * 
     * @return int Value of Athlete compared to a different Athlete
     */
    @Override
    public int compareTo(Athlete<E> athlete) {
        return this.compareTo(athlete);
    }

    /**
     * Override of toString method
     * 
     * @return String format string of the form name (sport - ranking)
     */
    @Override
    public String toString() {
        // creates formatted string of Athlete
        String format = this.getName() + " (" + this.getSport() + " - " + this.getRanking() + ")";
        return format;
    }
}
