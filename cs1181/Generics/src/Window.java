import java.awt.*;

import java.awt.event.*;

import javax.swing.*;

public class Window extends JFrame {

    private JButton button1;

    int clicks = 0;

    public Window(String title) {

        super(title);

        JPanel content = new JPanel();

        content.setLayout(new BoxLayout(content, BoxLayout.PAGE_AXIS));

        this.setContentPane(content);

        button1 = new JButton("Button 1");

        content.add(button1);

        JButton button2 = new JButton("Button 2");

        content.add(button2);

        button1.addActionListener(e -> {

            clicks++;

            button1.setText("Clicks: " + clicks);

        });

    }

    public static void main(String[] args) {
        // Create an application window using the MyFrame class
        Window window = new Window("Title");
        // Set the window to exit when closed, set the size,
        // and make it visible (then exit main())
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(300, 300);
        window.setVisible(true);
    }

}
