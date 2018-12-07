import java.awt.MenuBar;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Example extends JFrame {
 
    MenuBar mb = new MenuBar();;
    public Example()
    {
       setTitle("Exemplo Simples");
       setSize(1000, 200);
       setLocationRelativeTo(null);
       setDefaultCloseOperation(EXIT_ON_CLOSE);
       setMenuBar(mb); 
    }

    public static void main(String[] args) {
       Example ex = new Example();
       ex.setVisible(true);
    }
}