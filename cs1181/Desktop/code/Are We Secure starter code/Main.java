/**
 * The main class that contains the code being ran and printed.
 * 
 * @Author Hannah Wysong
 * @Version 1.1
 * @see User class
 * @see SecureUser class
 */
public class Main {
    /**
     * The main method. Creates users based on a given username and password.
     * Tests the passwords validity using methods from User and
     * SecureUser classes
     * 
     * @param args The command line arguments
     */
    public static void main(String[] args) {

        SecureUser user1 = new SecureUser("Michelle", "12345");
        System.out.println("1. " + user1.isValidPassword()); // false -- less than 8 characters

        SecureUser user2 = new SecureUser("Michelle", "12345Michelle");
        System.out.println("2. " + user2.isValidPassword()); // false -- contains username

        SecureUser user3 = new SecureUser("Michelle", "12345678");
        System.out.println("3. " + user3.isValidPassword()); // true

        System.out.println("4. " + user2.authenticate("ABCDE")); // false -- incorrect password

        System.out.println("5. " + user2.authenticate("12345")); // false - incorrect password

        System.out.println("6. " + user2.authenticate("1234Michelle")); // false -- incorrect password

        System.out.println("7. " + user2.authenticate("12345Michelle")); // false -- after third incorrect

        System.out.println("8. " + user3.authenticate("12345678")); // true

    }

}
