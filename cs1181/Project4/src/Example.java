import java.util.ArrayList;

/**
 * Driver Class for Project 4. Creates all of threads based on the threadNum. As 
 * well as creates the arrayList containg all possible combinations. 
 * 
 * @author Hannah Wysong
 */
public class Example {

	public static ArrayList<String> possiblePass = new ArrayList<>(); // potential combination arraylist
	public static int length = 3; // length of password

	// protected3 w/ 3 threads took 34079 ma
	// protected3 w/ 4 threads took 25411 ms
	/**
	 * Main method for Driver class. Creates all the threads and then joins them. Keeps track 
	 * of the program start time.
	 * 
	 * @param args command line arguments
	 */
	public static void main(String[] args) {

		long start = System.currentTimeMillis(); // start time

		int numThread = 13; // number of threads
		String filename = "protected" + length + ".zip"; // filename

		passCombinations(possiblePass, "", length);

		MultiThread[] threads = new MultiThread[numThread]; // array of custom threads
		int scale = possiblePass.size() / numThread; // scale for thread start or end
		for (int i = 0; i < numThread; i++) { // creates threads based on numThread
			int startIndex = i * scale; // calculates start value
			int endIndex = Math.min((i + 1) * scale, possiblePass.size()); // calculates end value
			threads[i] = new MultiThread(startIndex, endIndex, possiblePass, filename, start); // creates thread
			threads[i].start(); // runs thread
		}

		for (MultiThread thread : threads) { // loops through threads
            try {
                thread.join(); // joins so threads run concurrently
            } catch (InterruptedException e) {
                e.printStackTrace(); // throws an error if interupted
            }
        }
	}


	/**
	 * Method that uses an array of the alphabet to recursively create all potential passwords
	 * 
	 * @param combinations ArrayList<String> potential password list
	 * @param password password being generated
	 * @param lengths length of password generated
	 */
	private static void passCombinations(ArrayList<String> combinations, String password, int lengths) {

		char[] alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

		if (lengths <= 0) { // base case
			return;
		}
		for (int i = 0; i < alphabet.length; i++) { // iterates through alphabet
			String passCombo = password + alphabet[i]; // creates new passcode
			int numChar = passCombo.length();
			if (numChar == length) { // assures passcode is of correcct length
			combinations.add(passCombo); // adds to arraylist
			}
			passCombinations(combinations, passCombo, lengths - 1); // recursive call
		}
	}
}
