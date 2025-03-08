import java.util.ArrayList;
import java.util.Random;

/**
 * Class creating the chromosome object. Assigns it an arrayList 
 * of items. Performs mutations and crossovers on the list. Also creates a 
 * fitness value to be compared and printed.
 * 
 * @author Hannah Wysong
 */
public class Chromosome extends ArrayList<Item> implements Comparable<Chromosome> {

    private static Random rng = new Random();

    /**
     * Blank constructor method for chromosome object
     */
    public Chromosome() {
    }

    /**
     * Adds a copy of ech of the items passed into this Chromosome.
     * Uses a random number to decide whether the item's included field is
     * set to true or false.
     * 
     * @param items ArrayList of item objects
     */
    public Chromosome(ArrayList<Item> items) {
        //adds item to arrylist 
        for (Item item : items){
            this.add(new Item(item));
            // assigns included value based on random value
            this.get(this.size() - 1).setIncluded(rng.nextBoolean());
        }

    }

    /**
     * Creates and returns a new child chromosome by performing the crossover
     * operation on this chromosome and the other one that is passed in based
     * on a random number
     * 
     * @param other second parent chromosome object
     * @return Chromosome child being created
     */
    public Chromosome crossover(Chromosome other) {
        Chromosome child = new Chromosome();
        Item parentItem;
        //iterates through elements of parent chromosome
        for (int i = 0; i < this.size(); i++){
            //choses which parent based on random generation
            if (rng.nextDouble() < 0.5){
                parentItem = this.get(i);
                child.add(parentItem);
            }
            else {
                parentItem = other.get(i);
                child.add(parentItem);
            } 
        }
        return child;
    }

    /**
     * Performs the mutation operation on this chromosome using a
     * random number to decide whether to flip its included value
     * from false to true or vise versa.
     */
    public void mutate() {
        //iterates through item objects in chromosome
        for (Item item : this){
            // low chance of mutating
            if (rng.nextDouble() < 0.1){
                // switches values
                item.setIncluded(!item.isIncluded());
            }
        }
    }

    /**
     * Determines the fitness or weight and value of an item. If the
     * sum of all of the weight is greater than 10, the fitness is
     * 0. Otherwise, the fitness is equal to the objects value.
     * 
     * @return int 
     */
    public int getFitness() {
        double totalWeight = 0;
        int totalValue = 0;
        //iterates through item objects in chromosome
        for (Item item : this){
            if (item.isIncluded()){
                //adds value if item is included
                totalWeight += item.getWeight();
                totalValue += item.getValue();
            }
        }
       if (totalWeight < 10){
        return totalValue;
       }
       else {
        totalValue = 0;
       }
       return totalValue;
    }
    /**
     * Override of compareTo method to compare fitness values. Returns -1 
     * if orginal chromosome fitness is greater than the other chromosome.
     * Returns 1 if it is less, and returns 0 if the fitness is equal.
     * 
     * @return int value based on comparison
     */
    @Override
    public int compareTo(Chromosome other) {
        return Integer.compare(other.getFitness(), this.getFitness());
    }

    /**
     * toString method that creates a string with the
     * name, weight, and value of all of the items in the 
     * chromosome which are included, followed by fitness of the
     * chromosome.
     * 
     * @return String format 
     */
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        //iterates through items of the chromosome
        for (Item item : this){
            if (item.isIncluded()){
                // calls item.toString and adds it to String
                // also adds thee new line to String
                stringBuilder.append(item.toString()).append("\n");
            }
        }
            // adds the fitness value to String
            stringBuilder.append("Fitness: ").append(getFitness());
            return stringBuilder.toString();
    }
}
