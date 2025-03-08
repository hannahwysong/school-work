import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;

public class YellowPanel extends JPanel {
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.YELLOW);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(Color.RED);
        g.fillRect(getWidth() / 2, 0, getWidth(), getHeight());
    }
}
