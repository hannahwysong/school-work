import javax.swing.*;
/**
 * Main class that initalizes the JFrame
 * 
 * @author Hannah Wysong
 */
public class GUImain {
    /**
     * Main method that initalizes the JFrame using the tempConvertFrame.
     * It sets the size and the close operation.
     * 
     * @param args Command line arguments
     */
    public static void main(String[] args) {
        // creates new frame 
        tempConvertFrame myFrame = new tempConvertFrame();
        myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myFrame.setVisible(true);
        //automatically sets widget sizes on window
        myFrame.pack();
    }
}