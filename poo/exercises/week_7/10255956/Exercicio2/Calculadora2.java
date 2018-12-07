import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.lang.Double;

/**
 * Calculadora
 */
public class Calculadora2 
{
    private JFrame frame;
    private JTextField numStr1, numStr2;
    private JButton somaOp, multiplicacaoOp;
    private JLabel  resultLabel;

    public Calculadora2()
    {
        makeFrame();
    }
    
    private void makeFrame()
    {
        frame = new JFrame("Calculadora");

        numStr1 = new  JTextField(5);
        
        
        numStr2 = new  JTextField(5);
        

        resultLabel = new JLabel(" = ");

        somaOp = new JButton("+");
        somaOp.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {  
                    double num1 = Double.parseDouble(numStr1.getText());
                    double num2 = Double.parseDouble(numStr2.getText());
                    Double res = new Double(num1 + num2);
                    resultLabel.setText(" = " + res.toString());
                }
            }
        );
        
        multiplicacaoOp = new JButton("*");
        multiplicacaoOp.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {  
                    double num1 = Double.parseDouble(numStr1.getText());
                    double num2 = Double.parseDouble(numStr2.getText());
                    Double res = new Double(num1 * num2);
                    resultLabel.setText(" = " + res.toString());
                }
            }
        );
        
        frame.setLayout(new FlowLayout());
        frame.setSize(500, 100);
        frame.add(numStr1);
        frame.add(numStr2);
        frame.add(somaOp);
        frame.add(multiplicacaoOp);
        frame.add(resultLabel);

        frame.setVisible(true);
    }
    
    public static void main(String[] args)
    {
        Calculadora calculadora = new Calculadora2();    
    }
}