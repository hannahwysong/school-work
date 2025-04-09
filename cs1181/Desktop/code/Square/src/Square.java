/**
 * Object class for Square object defines area and perimeter
 * 
 * @author Hannah Wysong
 */
public class Square {

    private double side;
    
    /**
     * Object initalizer defining side lengths
     * 
     * @param side length of of the square
     */
    public Square(double side){
        this.side = side;
    }

    /**
     * Getter method for the side length
     * 
     * @return the side length
     */
    public double getSide(){
        return this.side;
    }

    /**
     * getter method for the perimeter, which is calculated
     * using the side length
     * 
     * @return the square perimeter
     */
    public double getPerimeter(){
        double perimeter = (this.side * 4);
        return perimeter;
    }

    /**
     * getter method for the area, calculated using the
     * side length of the square.
     * 
     * @return the square area
     */
    public double getArea(){
        double area = this.side * this.side;
        return area;
    }

    /**
     * Override of the to string method. Returns a string of the length,
     * area and perimeter
     * 
     * @return String formatted of side, area, and perimeter
     */
    @Override
    public String toString(){
        String formatted = "Square with side = " + getSide() + "\n" + "The perimeter of the square is " + getPerimeter() + "\n" + "The area of the square is " + getArea();
        return formatted;
    }
}
