/*
* Creates a SecureUser object with a password and
*  a username. Ovverides the parent class's method
*  authenticate to add a conter for incorrect attempts.
*
* @see User class
* @Author Hannah Wysong 
* @Version 1.1
*/
public class SecureUser extends User {

    private int numIncorrect = 0;

    /**
     * Creates the user object and establishes the parameters.
     * The paramets come from the parent class User.
     * 
     * @param Username the given username for the User
     * @param Password the given password for the User
     */
    public SecureUser(String username, String password) {
        super(username, password);
    }

    /**
     * Authenticates that the given password is the same as
     * the User's password. After it assigns a value based
     * on the amount of attempts incorrect. It always returns
     * false after the third incorrect attempt.
     * 
     * @param inputPassword the password being authenticated
     * @return Boolean value of if the password matches the User password
     */
    @Override
    public boolean authenticate(String inputPassword) {
        boolean authenticated = super.authenticate(inputPassword);
        if (authenticated == false) {
            this.numIncorrect += 1;
            return authenticated;
        }
        if (numIncorrect >= 3) {
            return false;
        }
        return authenticated;
    }
}