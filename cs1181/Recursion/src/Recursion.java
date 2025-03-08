public class Recursion {
    public static void main(String[] args) {
        System.out.println(reverse("hello"));
    }
        
        public static void foo(int times) {
            if (times > 100 ){
                return;
            }
            System.out.println("Times: " + times);
            foo(times + 1);
        }

        public static String reverse(String theString) {
            // base case : 
            if (theString.length() == 0) {
                return theString;
            }

            // divide the problem
            String firstChar = theString.substring(0, 1);
            

            // trust
            String theRest = reverse(theString.substring(1));
            return theRest + firstChar;
        }
    }

