/**
 * Class creating the item object. Assigns it a name, weight, and value.
 * Also creates a deep copy of the object. Includes getter methods, and a 
 * setter method for the included value. 
 * 
 * @author Hannah Wysong
 */
public class Item {

    private final String name;
    private final double weight;
    private final int value;
    private boolean included = false;

    /**
     * Initalizies item object
     * 
     * @param name
     * @param weight
     * @param value
     */
    public Item(String name, double weight, int value) {
        // 
        this.name = name;
        this.weight = weight;
        this.value = value;
    }

    /**
     * Initalizing item object with elements of other item
     * 
     * @param other
     */
    public Item(Item other) {
        // creating a deep copy
        this.name = other.name;
        this.weight = other.weight;
        this.value = other.value;
    }

    /**
     * Setter method for the included field
     * 
     * @param included
     */
    public void setIncluded(boolean included) {
        this.included = included;
    }

    /**
     * Getter method for object weight
     * 
     * @return double Weight 
     */
    public double getWeight() {
        return this.weight;
    }

    /**
     * Getter method for object value
     * 
     * @return int Weight 
     */
    public int getValue() {
        return this.value;
    }

    /**
     * /**
     * Getter method for the included field
     * 
     * @return boolean included
     */
    public boolean isIncluded() {
        return this.included;
    }

    
    @Override
    /**
     *Override toString method that returns a string of the form,
     * object.name (object.weight lbs, $object.value)
     * 
     * @return String format
     */
    public String toString() {
        String format = (name + "(" + weight + " lbs, $" + value + ")");
        return format;
    }
}
