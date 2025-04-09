import java.util.Scanner;

/**
 *  Class containing the main method and other methods
 */
public class Lab3aStartingCode {

    static Scanner input = new Scanner(System.in);

    /**
     * The main method.
     * 
     * @param args The command line arguments
     */
    public static void main(String[] args) {

        Clock appointmentTime = new Clock(12, 30, "p.m.");
        Clock userTime = new Clock(getUserHours(), getUserMinutes(),
                getUserMeridian());

        if (Clock.getEarlier(userTime, appointmentTime) == userTime) {
            System.out.println("You're not late!");
        } else {
            System.out.println("You're late!");
        }

    }

    /**
     * Gets the number of hours from the user
     * 
     * @return int hours
     */
    public static int getUserHours() {
        System.out.print("What hour should the clock be set to? ");
        int hours = input.nextInt();
        input.nextLine(); // consumes the trailing newline
        return hours;
    }
    /**
     * Gets the number of minutes from the user
     * 
     * @return int minutes
     */
    public static int getUserMinutes() {
        System.out.print("What minute should the clock be set to? ");
        int hours = input.nextInt();
        input.nextLine(); // consumes the trailing newline
        return hours;
    }
    /**
     * Gets the merdian from the user
     * 
     * @return String merdian a.m. or p.m.
     */
    public static String getUserMeridian() {
        System.out.print("Is it a.m. (a) or p.m. (p)? ");
        String answer = input.nextLine();
        if (answer.toLowerCase().startsWith("a")) {
            return "a.m.";
        } else {
            return "p.m.";
        }
    }

}
