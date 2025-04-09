/**
 * The class creates the Golfer object. it assigns the 
 * object a first name, last name, score, and thru
 * 
 * @Author Hannah Wysong
 * @see comparable
 */
public class Golfer implements Comparable<Golfer>{

    private String firstName;
    private String lastName;
    private int score;
    private int thru;

    /**
     * The constructor of the golfer object. Assigns all variables
     * with placeholders.
     */
    public Golfer(){
        firstName = "empty";
        lastName = "empty";
        score = -1;
        thru = -1;
    }

    /**
     * Another constructor for the golfer object, assigns each
     * parameter to the given value.
     * 
     * @param firstName The golfer first name
     * @param lastName The golfer last name
     * @param score The golfer score
     * @param thru The number of holes
     */
    public Golfer(String firstName, String lastName, int score, int thru){
        this.firstName = firstName;
        this.lastName = lastName;
        this.score = score;
        this.thru = thru;
    }

    /**
     * Override method for toString to return the 
     * string for the last, first name of the golfer and
     * their score and number of wholes.
     * 
     * @return String golfer parameters
     */
    @Override 
    public String toString(){
        return lastName + ", " + firstName + ": " + score + " through " + thru;
    }

    /**
     * An override method to compare the objects. The method compares
     * the objects based on score, number of holes, and lexicographically
     * first and last name. Returns a value to sort the arraylist.
     * 
     * @param other Golfer Object
     * @return int value to sort objects
     */
    @Override
    public int compareTo(Golfer other){
        if (this.score > other.score){
            return 1;
        }
        else if (this.score < other.score){
            return -1;
        }
        else if (this.thru > other.thru){
            return -1;
        }
        else if (this.thru < other.thru){
            return 1;
        }
        else{
        if (this.firstName.compareToIgnoreCase(other.firstName) < 0) {
            return -1;
        }
        else if (this.firstName.compareToIgnoreCase(other.firstName) > 0){
            return 1;
        }
    }
        return (this.lastName.compareToIgnoreCase(other.lastName));
    }
}

