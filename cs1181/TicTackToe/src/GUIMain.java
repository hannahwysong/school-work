import javax.swing.JFrame;

/**
 * Main class for MyFrame class
 * 
 * @author Hannah Wysong
 */
public class GUIMain {
    /**
     * Creates a new MyFrame and sets parameters
     * @param args Command line arguments
     */
    public static void main(String[] args) {
       MyFrame window = new MyFrame();
       window.setSize(300,300);
       window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       window.setVisible(true); 
    }
}
