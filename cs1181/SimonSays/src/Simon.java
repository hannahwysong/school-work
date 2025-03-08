import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Class using the JFrame extension to create the game window. Also implements the 
 * game pieces.
 * 
 * @author Hannah Wysong
 */
public class Simon extends JFrame implements ActionListener {

    // 
    private JButton[] buttons;
    private ArrayList<Integer> pattern;
    private int patternIndex;
    private Random rng = new Random(4);
    private Timer timer;

    /**
     * Constructor method for Simon class, creates the JPanel and 
     * adds buttons and text. 
     * 
     * The opacity is commented out due to differences between mac and windows
     */
    public Simon() {

        // implments main jframe
        super();
        setTitle("Simon Says!");
        setSize(300, 300);

        // creates panel
        JPanel content = new JPanel();
        this.setContentPane(content);
        content.setLayout(new BorderLayout());
        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new GridLayout(2, 2));
        content.add(centerPanel, BorderLayout.CENTER);

        // adds instructors
        JLabel instructions = new JLabel("  Follow the Pattern - Click the Right Buttons!");
        content.add(instructions, BorderLayout.NORTH);

        buttons = new JButton[4];
        // creates red button
        JButton redButton = new JButton();
        redButton.setBackground(Color.RED);
        //redButton.setOpaque(false);
        redButton.setBorderPainted(false);
        redButton.addActionListener(this);
        buttons[0] = redButton;
        centerPanel.add(redButton);

        // creates blue button
        JButton blueButton = new JButton();
        blueButton.setBackground(Color.BLUE);
        //blueButton.setOpaque(false);
        blueButton.setBorderPainted(false);
        blueButton.addActionListener(this);
        buttons[1] = blueButton;
        centerPanel.add(blueButton);

        // creates yellow button
        JButton yellowButton = new JButton();
        yellowButton.setBackground(Color.YELLOW);
        //yellowButton.setOpaque(false);
        yellowButton.setBorderPainted(false);
        yellowButton.addActionListener(this);
        buttons[2] = yellowButton;
        centerPanel.add(yellowButton);

        // creates green button
        JButton greenButton = new JButton();
        greenButton.setBackground(Color.GREEN);
        //greenButton.setOpaque(false);
        greenButton.setBorderPainted(false);
        greenButton.addActionListener(this);
        buttons[3] = greenButton;
        centerPanel.add(greenButton);

        //creates pattern array and starts game
        pattern = new ArrayList<>();
        startPattern();
    }

    /**
     * ActionPerfromed method for the actionlister added to the buttons. The
     * listener records the imput and compares it to the correct button. If the 
     * button is correct, then it compares the pattern to check if it is correct
     * finally, it continues the game or ends if the pattern is incorrect. 
     * 
     * The code handles the button input but doesn't do anyhthing with the code. I
     * do not know why. Instead of immediately executing the rest of the code, it does not
     * update the pattern index or end the code when incorrect inputs are given. It seems to
     * run on its own time and eventually quit.
     * 
     * @param ActionEvent e Records the input of JButton
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        // assigns input with a new button
        JButton clickedButton = (JButton) e.getSource();
        int index = 0;
        for (int i = 0; i < 4; i++) {
            // checks if inputted button is correct
            if (clickedButton.equals(buttons[i])) {
                index = i;
                break;
            }
        }
        // checks if button was clicked in the right pattern 
        if (index == pattern.get(patternIndex)) {
            patternIndex++;
            if (patternIndex == pattern.size()) {
                addPattern();
                playPattern();
                patternIndex = 0;
                // exits the system if either incorrect
            } else {
                JOptionPane.showMessageDialog(this, "Game Over, Your Score Was: " + String.valueOf(patternIndex));
                System.exit(0);
            }

        }
    }

    /**
     * Method that starts the game. Clears the previous pattern and restarts the index. 
     * Starts with the first button.
     */
    private void startPattern() {
        pattern.clear();
        patternIndex = 0;
        addPattern();
        playPattern();
    }

    /**
     * Plays the pattern by going through each button in the pattern and flashing 
     * the color.
     */
    private void playPattern() {
        for (int i = 0; i < pattern.size(); i++) {
            flashButton(i);
        }
    }

    /**
     * Adds a random new button to the pattern based off a random value one to four
     */
    private void addPattern() {
        pattern.add(rng.nextInt(4));
    }

    /**
     * The method uses two timers to flash the button color on and off. The first timer turns the
     * opacity on. It waits to turn the second one on until the specified time passes based on 
     * which button is clicked. The second timer turns the opacity off after the specified amount of time.
     * 
     * @param index int which button in an order of one to four
     */
    public void flashButton(int index) {
        // timer turns on opacity
        timer = new Timer(1000 * index, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                buttons[index].setOpaque(true);
                repaint();
                // timer turns opacity back off
                Timer newTimer = new Timer(1000, new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        buttons[index].setOpaque(false);
                        // changes the color of the button
                        repaint();
                    }
                });
                newTimer.setRepeats(false);
                newTimer.start();
            }
        });
        timer.setRepeats(false);
        timer.start();
    }
}
