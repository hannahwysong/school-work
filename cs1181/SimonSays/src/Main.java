import javax.swing.JFrame;

/**
 * Main class for SimonSays game. Creates the JFrame.
 */
public class Main {
    /**
     * The main method. Creates the JFrame and sets it to be visable and close on exit.
     * 
     * @param args The command line arguments
     */
    public static void main(String[] args) {
        Simon window = new Simon();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
    }
}
