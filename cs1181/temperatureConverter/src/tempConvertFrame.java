import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * JFrame class that sets the content on the frame. Includes two JLabels.
 * a title, two textboxes, and a button.
 * 
 * @author Hannah Wysong
 */
public class tempConvertFrame extends JFrame implements ActionListener {
    private JLabel tempFahren;
    private JLabel tempCel;
    private JTextField fahrenField;
    private JTextField celField;
    private JButton calcButton;

    /**
     * Constructor class for the JFrame. Adds the title, labels, text
     * boxes and button to the frame. Also uses GridBag layout to place
     * the items in the frame.
     */
    tempConvertFrame() {

        setTitle("Temperature Converter");

        // creates labels
        tempFahren = new JLabel("Fahrenheit");
        tempCel = new JLabel("Celcius");

        // creates text fields and set editable status
        fahrenField = new JTextField(15);
        fahrenField.setEditable(true);

        celField = new JTextField(15);
        celField.setEditable(false);

        // creates button and adds action listener
        calcButton = new JButton("Convert");
        calcButton.addActionListener(this);

        // sets layout to gridbag 
        GridBagConstraints positionConst = null;
        setLayout(new GridBagLayout());
        positionConst = new GridBagConstraints();

        // sets position of farhenheit label and text field
        positionConst.gridx = 0;
        positionConst.gridy = 0;
        positionConst.insets = new Insets(10, 10, 10, 10);
        add(tempFahren, positionConst);

        positionConst.gridx = 1;
        positionConst.gridy = 0;
        positionConst.insets = new Insets(10, 10, 10, 10);
        add(fahrenField, positionConst);

        // sets position of celsius label and text field
        positionConst.gridx = 0;
        positionConst.gridy = 1;
        positionConst.insets = new Insets(10, 10, 10, 10);
        add(tempCel, positionConst);

        positionConst.gridx = 1;
        positionConst.gridy = 1;
        positionConst.insets = new Insets(10, 10, 10, 10);
        add(celField, positionConst);

        // sets the position of the button
        positionConst.gridx = 0;
        positionConst.gridy = 2;
        positionConst.insets = new Insets(10, 10, 10, 10);
        add(calcButton, positionConst);
    }

    /**
     * ActionListener method takes input from text field and converts 
     * temp. from fahrenheit to celsius. Checks for NumberFormatException
     * and tells user to input a number. When an event occurs, the 
     * method is called.
     */
    public void actionPerformed(ActionEvent event) {
        String userInput;
        int temperature = 0;

            userInput = fahrenField.getText();
            try{
                //tries to convert temperature
                    temperature = Integer.parseInt(userInput);
                    temperature = (temperature - 32) * 5/9; 
                    // if error is not found, the program continues
                    celField.setText(Integer.toString(temperature));
                }
                catch (NumberFormatException e) {
                    // catches the error and sends an error message to terminal
                    System.out.println("Error must enter a number");
                }
                

            }
        }
