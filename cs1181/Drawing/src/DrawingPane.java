import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DrawingPane extends JComponent {
    @Override
    public void paintComponent(Graphics g) {
        g.setColor(Color.BLACK);
        g.drawOval(50, 50, 75, 75);
    }
}
