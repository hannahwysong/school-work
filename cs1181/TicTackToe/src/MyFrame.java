import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

/**
 * JFrame Class that creates the TicTacToe board and buttonListener
 * 
 * @author Hannah Wysong
 */
public class MyFrame extends JFrame {

    private ArrayList<JButton> buttonList = new ArrayList<>();
    private int clicks = 0;
    private int num = 0;
    private JLabel playerStatus = new JLabel("Game Status");

    /**
     * Constructor class of MyFrame. Creates the JPanel and adds 
     * the necessary buttons and text 
     */
    public MyFrame(){

    super();
    // creates base panel 
    JPanel content = new JPanel();
    content.setLayout(new BorderLayout());
    this.setContentPane(content);

    
    content.add(playerStatus, BorderLayout.SOUTH);
    // adds new panel to organize buttons in grid layout
    JPanel gridPanel = new JPanel();
    gridPanel.setLayout(new GridLayout(3,3));
    content.add(gridPanel, BorderLayout.CENTER);
    
    //creates buttons and adds to arrayList of buttons
    // also adds buttos to the panel
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            num = num + 1;
            JButton button = new JButton(Integer.toString(num));
            buttonList.add(button);
            button.setEnabled(true);
            gridPanel.add(button);
            // adds button listener that responds to clicks
            buttonListener listener = new buttonListener();
            button.addActionListener(listener);
        }
    }
    
}
    /**
    * Button Listener class that uses an action listener to record
    * which button is clicked
    */
    class buttonListener implements ActionListener {

        /**
         * Takes input from user clicks and associates it with the 
         * correct button and changes it to "X" or "O" depending 
         * on the player.
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            int index = 0;
            clicks++;
            // sorts through button arrayList and assoicates it with the 
            // button being clicked.
            for (int buttonIndex = 0;buttonIndex < buttonList.size(); buttonIndex++) {
             if (e.getSource() == buttonList.get(buttonIndex)){
                index = buttonIndex;

             }
            }
            // checks if button is already changed
            if (buttonList.get(index).getText().equals("X") || buttonList.get(index).getText().equals("O")) {
            }
            else {
                // checks button is the same
                if (e.getSource() == buttonList.get(index)) {
                    // checks which players turn
                    if (clicks % 2 == 0) {
                        // changes the text
                        (buttonList.get(index)).setText("O");
                        playerStatus.setText("Player 2's turn");
                    }
                    else {
                        (buttonList.get(index)).setText("X");
                        playerStatus.setText("Player 1's turn");
                    }
                }
            }
        }

        }
    }

