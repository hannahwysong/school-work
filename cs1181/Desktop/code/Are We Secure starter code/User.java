/**
 * A user object that stores a name and password. It also checks the password
 * for
 * validity - meaning 8 or more characters and not containing the username.
 * After
 * accepting password it authenticates to make sure the inputted password is
 * the same as the given password
 * 
 * @Author Hannah Wysong
 * @Version 1.1
 */
public class User {

    private String username;
    private String password;

    /**
     * Creates the user object and establishes the parameters.
     * 
     * @param Username the given username for the User
     * @param Password the given password for the User
     */
    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    /**
     * Checks the password to see if it contains more than eigth characters
     * or does not contain the username.
     * 
     * @return boolean value for if the password is valid or not
     */
    public boolean isValidPassword() {
        return password.length() >= 8 && !password.contains(username);
    }

    /**
     * Authenticates that the given password is the same as
     * the User's password.
     * 
     * @param inputPassword the password being authenticated
     * @return boolean value of if the password matches the User password
     */
    public boolean authenticate(String inputPassword) {
        return inputPassword.equals(password);
    }
}
