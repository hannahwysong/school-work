import java.awt.*;
import javax.swing.*;

public class Memory extends JFrame{

    private JLabel instructions;
    private JButton buttonRed;
    private JButton buttonBlue;
    private JButton buttonYellow;
    private JButton buttonGreen;
    
    public Memory() {
        super();
        
        JPanel content = new JPanel();
        content.setLayout(new GridLayout());
        this.setContentPane(content);

        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new GridLayout(2,2));
        content.add(centerPanel, BorderLayout.CENTER);

        // creates red button
        buttonRed = new JButton();
        //buttonRed.setBackground(Color.RED);
        //buttonRed.setOpaque(true);
        //buttonRed.setBorderPainted(false);
        centerPanel.add(buttonRed);
        // records button input
        buttonRed.addActionListener(e -> System.out.println("Handled by Lambda listener"));

        // creates blue button
        buttonBlue  = new JButton();
        //buttonBlue.setBackground(Color.BLUE);
        //buttonBlue.setOpaque(true);
        //buttonBlue.setBorderPainted(false);
        centerPanel.add(buttonBlue);
        // handles button input
        buttonBlue.addActionListener(e -> System.out.println("Handled by Lambda listener"));

        // creates green button
        buttonGreen = new JButton();
        //buttonGreen.setBackground(Color.GREEN);
        //buttonGreen.setOpaque(true);
        //buttonGreen.setBorderPainted(false);
        centerPanel.add(buttonGreen);
        // handles button input
        buttonGreen.addActionListener(e -> System.out.println("Handled by Lambda listener"));

        // creates yellow button
        buttonYellow = new JButton();
        //buttonYellow.setBackground(Color.YELLOW);
        //buttonYellow.setOpaque(true);
        //buttonYellow.setBorderPainted(false);
        centerPanel.add(buttonYellow);
        // handles button input
        buttonYellow.addActionListener(e -> System.out.println("Handled by Lambda listener"));


    }
}
