import java.util.ArrayList;

/**
 * Main class for the Primethread. Uses the thread to run through all of the numbers from 0
 * to 10 million. If the number is prime, a point is added to a counter. It is split
 * up using four threads to reduce runtime. 
 * 
 * @author Hannah Wysong
 */
public class App {
    /**
     * Main method for Counting_Primes, records the number of prime numbers between 
     * 0 and 10 million. 
     * 
     * @param args command line arguments 
     * @throws InterruptedException 
     */
    public static void main(String[] args) throws InterruptedException {

        long startTime = System.currentTimeMillis();

        int n = 100000000;
        int numThread = 4;
        int start = 1;
        int change = (n / numThread);
        int end = change;

        // increment by change to get start and end


        // creates an arraylist of threads
        ArrayList<PrimeThread> threadList = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            // creates a thread with a start and end 
            PrimeThread thread = new PrimeThread(start, end);
            threadList.add(thread);
            start = end;
            end = end + change;
        }

        // starts the thread
        for (PrimeThread t : threadList) {
            t.start();
        }

        // joins all of the threads so they dont run inconcurrently
        for (PrimeThread t : threadList) {
            t.join();
        }

        // adds points to results if prime
        int sum = 0;
        for (PrimeThread t : threadList) {
            sum = sum + t.getResult();

        }
        System.out.println(sum);
        long endTime = System.currentTimeMillis();
        System.out.println("Program took: " + (endTime - startTime) + " miliseconds");
    }
}
