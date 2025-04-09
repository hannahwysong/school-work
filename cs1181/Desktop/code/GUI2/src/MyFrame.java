import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private int clicks = 0;
    //private JLabel label;
    private JButton button;

    public MyFrame(){
        super();
        //label = new JLabel("Click Me!");
        JPanel content = new JPanel();
        this.setContentPane(content);
        //getContentPane().add(label);

        //inner class
        // class ButtonListener implements ActionListener{
        //     @Override
        //     public void actionPerformed(ActionEvent e){
        //         clicks++;
        //         button.setText("Clicks: " + clicks);
        //     }
        // }
        
        button = new JButton("Click me");
        getContentPane().add(button);
        // ButtonListener myListener = new ButtonListener();

        // anonymous inner class
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                clicks++;
                button.setText("Clicks: " + clicks);
            }
        });

    }

}
