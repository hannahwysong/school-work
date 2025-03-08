/**
 * PrimeThread class used to create a new thread. The thread is used to iterate
 * over a section of numbers and count the amount of prime numbers. 
 * 
 */
public class PrimeThread extends Thread {

    public int start;
    private int result;
    public int end;

    /**
     * constructor class for threads, contains the start and end of thread
     * 
     * @param start int begining of thread
     * @param end int end of thread
     */
    public PrimeThread(int start, int end) {
        this.start = start;
        this.end = end;
        this.result = 0;
    }

    /**
     * Overide of run method for threads. Adds one to result if the number being 
     * checked is prime.
     */
    @Override
    public void run() {
        for (int i = start; i < end; i++) {
            if (isPrime(i)) {
                result++;
            }
        }
    }

    /**
     * Returns the result value
     * 
     * @return int result the total number of prime numbers
     */
    public int getResult() {
        return result;
    }

    /**
     * Determines if the given number is prime or not. Method was given with the 
     * instructions.
     * 
     * @param n int the given number 
     * @return boolean if prime or not
     */
    public static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}
