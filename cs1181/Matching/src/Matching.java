/**
 * Public Matching class that checks if the given string is of the form "()"
 * 
 * @author Hannah Wysong
 */
public class Matching {
    /**
     * nestParen method for Matching class. If the inputted string is one char
     * or less, the test automatically reeturns false. If it has more then two,
     * the program checks if the first and last char is equal to '(' and ')'. If
     * true, it recursively calls the method on a substring of the remaining chars.
     * Otherwise, returns true.
     * 
     * @param n String element being tested
     * @return boolean value for if test passes
     */
    public static boolean nestParen(String n) {
        String subStrMid = "";
        // base case:
        if (n.length() <= 1) {
            return false;
        } else {
            // creates substrings of first and last char
            String subStrFirst = n.substring(0, (n.length() - (n.length() - 1)));
            String subStrLast = n.substring(n.length() - 1);

            // checks if first is equal to (
            if (subStrFirst.equalsIgnoreCase("(")) {
                // checks if second is equal to )
                if (subStrLast.equals(")")) {
                    subStrMid = n.substring(1, n.length() - 1);
                } else {
                    // returns false if either is not true
                    return false;
                }
            } else {
                return false;
            }
            if (subStrMid.length() == 0) {
                // returns true if entire string passes test
                return true;
            } else {
                // recursively calls method if there is still remaining characters
                return nestParen(subStrMid);
            }

        }
    }

    /**
     * Main method for Matching class. Tests the nestParen method.
     * 
     * @param args Command Line Arguments
     */
    public static void main(String[] args) {
        System.out.println(nestParen("hello")); // false, not of form ()
        System.out.println(nestParen("()")); // true
        System.out.println(nestParen("(((x)))")); // false, contains other chars
        System.out.println(nestParen("(((((())))))")); // true
        System.out.println(nestParen("((((())))")); // false, uneven number of ()
    }
}
