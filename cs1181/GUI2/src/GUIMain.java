import javax.swing.JFrame;

public class GUIMain {
    public static void main(String[] args) {
        // Create an application window using the MyFrame class
        MyFrame window = new MyFrame();
        // Set the window to exit when closed, set the size,
        // and make it visible (then exit main())
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(300, 300);
        window.setVisible(true);
    }

}
