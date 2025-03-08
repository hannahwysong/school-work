import java.awt.event.*;
import javax.swing.*;

import javax.swing.JButton;

public class ButtonListener implements ActionListener {

    public void actionPerformed(ActionEvent e) {
        System.out.println("Wrong choice buddy");
        System.out.println(((JButton) e.getSource()).getText());

    }
}
