import javax.swing.JFrame;

public class GUIMain {
    public static void main(String[] args){
        MyFrame window = new MyFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(300,300);
        window.setVisible(true);

    }
}
