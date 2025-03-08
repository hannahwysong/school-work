import java.awt.*;

import java.awt.event.*;

import javax.swing.*;

// We begin our GUI by extending Jframe 

public class MyFrame extends JFrame {

    // All state variables that we want to use throughout the life
    // of the program are created here (NOT in main())
    private int clicks = 0;
    // We also keep reference variables for any graphics objects that we want
    // to modify in the future here:
    private JLabel label;
    private JButton button;
    private JPanel eastPanel;
    // My application window:

    public MyFrame() {
        super();
        // Create a new content Panel with a BorderLayout
        JPanel content = new JPanel();
        content.setLayout(new BorderLayout());
        this.setContentPane(content);
        // Put some borders around the edges of the content panel
        content.setBorder(BorderFactory.createEmptyBorder(0, 10, 10, 10));
        // Add some buttons
        // For the west section of the content panel, add another JPanel
        // with a BoxLayout and then add a stack up buttons
        JPanel westPanel = new JPanel();
        westPanel.setLayout(new BoxLayout(westPanel, BoxLayout.PAGE_AXIS));
        content.add(westPanel, BorderLayout.WEST);
        westPanel.add(new JButton("West1"));
        westPanel.add(new JButton("West2"));
        westPanel.add(new JButton("West3"));
        // For the center section, add another JPanel with a 3x3 GridLayout,
        // and fill it with buttons
        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new GridLayout(3, 3));
        for (int i = 0; i < 9; i++) {
            centerPanel.add(new JButton("Button"));
        }
        // Don't forget to add this new JPanel to the middle of the
        // main content panel!
        content.add(centerPanel, BorderLayout.CENTER);
        // In the south section, make yet antoher panel and fill it with a
        // stack of controls (like checkboxes)
        JPanel southPanel = new JPanel();
        southPanel.setLayout(new BoxLayout(southPanel, BoxLayout.LINE_AXIS));
        content.add(southPanel, BorderLayout.SOUTH);
        JCheckBox checkBox = new JCheckBox("Option 1");
        southPanel.add(checkBox);

        // Use a lambda expression for the item listener for the checkbox:
        checkBox.addItemListener(e -> {
            System.out.println("Option 1: ");
            System.out.println(e.getStateChange());
        });
        JCheckBox checkBox2 = new JCheckBox("Option 2");
        southPanel.add(checkBox2);
        // Use a lambda expression for the item listener for the checkbox:
        checkBox2.addItemListener(e -> {
            System.out.println("Option 2: ");
            System.out.println(e.getStateChange());
        });
        // Create an East Panel for some exclusive option radio buttons
        JPanel eastPanel = new JPanel();
        eastPanel.setLayout(new BoxLayout(eastPanel, BoxLayout.PAGE_AXIS));
        // Create three radio buttons
        JRadioButton radio1 = new JRadioButton("XOption 1", true);
        JRadioButton radio2 = new JRadioButton("XOption 2", false);
        JRadioButton radio3 = new JRadioButton("XOption 3", false);

        ActionListener myMenuListener = new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                String s = e.getActionCommand();
                switch (s) {
                    case "Red":
                        eastPanel.setBackground(Color.RED);
                        break;
                    case "Yellow":
                        eastPanel.setBackground(Color.YELLOW);
                        break;
                    case "Blue":
                        eastPanel.setBackground(Color.BLUE);
                        break;
                }
            }
        };
        // If we want them to be mutally exclusive (only one can be selected

        // at a time) then we need to put them into a ButtonGroup

        ButtonGroup group1 = new ButtonGroup();

        group1.add(radio1);

        group1.add(radio2);

        group1.add(radio3);
        // We'll use the same ItemListener for all three buttons, so

        // this is a good place to use an anonymous inner class instead

        // of a lambda expression

        ItemListener radioListener = new ItemListener() {

            @Override

            public void itemStateChanged(ItemEvent e) {

                // Since getSource() returns an Object, we must typecast

                // it to (JRadioButton) so that we can call .getText()

                System.out.println(((JRadioButton) e.getSource()).getText());

                System.out.println(e.getStateChange());

            }

        };

        // Now add the same ItemListener to all three buttons
        radio1.addItemListener(radioListener);
        radio2.addItemListener(radioListener);
        radio3.addItemListener(radioListener);
        // Add the three radio buttons to the east Jpanel
        eastPanel.add(radio1);
        eastPanel.add(radio2);
        eastPanel.add(radio3);
        // Don't forget to add the JPanel to our main content panel
        content.add(eastPanel, BorderLayout.EAST);
        // Create a menubar for our application
        String days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
        JList<String> myDayList = new JList<>(days);
        eastPanel.add(myDayList);
        myDayList.addListSelectionListener(e -> {
            // System.out.println(e.getSelectecValue().toString());
        });

        JMenuBar menuBar = new JMenuBar();
        // The first entry/menu in our menubar will be the color menu
        JMenu colorMenu = new JMenu("Color");
        menuBar.add(colorMenu);
        // Add three JMenuItems to the Color menu
        JMenuItem colorItem = new JMenuItem("Red");
        colorMenu.add(colorItem);
        colorItem = new JMenuItem("Yellow");
        colorMenu.add(colorItem);
        colorItem = new JMenuItem("Blue");
        colorMenu.add(colorItem);
        // Add the menuBar to our content panel in the north section
        // Since the menuBar is the only thing in the north section, we don't
        // need to create a new JPanel, we can add the menuBar directly to
        // our content panel
        content.add(menuBar, BorderLayout.NORTH);
    }
}
