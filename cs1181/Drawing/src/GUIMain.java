import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GUIMain {
    public static void main(String[] args) throws Exception {
        JFrame window = new JFrame("Drawing Window");
        JPanel content = new JPanel();
        window.setContentPane(content);
        content.setLayout(content, BoxLayout.PAGE_AXIS);

        DrawingPane drawingWindow = new DrawingPane();
        content.add(drawingWindow);

        window.setSize(500, 500);
        window.setLocation(250, 250);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
    }
}
