import javax.swing.*;

public class App {
    public static void main(String[] args) {

        JFrame window = new JFrame("this is a test");
        window.setSize(300, 300);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);

        YellowPanel myPanel = new YellowPanel();
        window.setContentPane(myPanel);

        JLabel label1 = new JLabel("You have two choices");
        myPanel.add(label1);

        JButton button1 = new JButton("ur gay and stupid");
        myPanel.add(button1);

        JButton button2 = new JButton("ur whole family dies");
        myPanel.add(button2);

        ButtonListener listener1 = new ButtonListener();
        button1.addActionListener(listener1);

        ButtonListener listener2 = new ButtonListener();
        button2.addActionListener(listener2);

        window.setVisible(true);
        count(15);
    }

    private static void count(int i) {
        for (int j = 0; j < i; j++) {
            System.out.println(j);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
