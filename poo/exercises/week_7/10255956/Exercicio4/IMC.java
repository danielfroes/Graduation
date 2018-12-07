import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JComponent;


/**
 * IMC
 */
public class IMC
{
    private JPanel topPanel;
    private JPanel centerPanel;
    private JFrame frame;
    private int hgap;
    private int vgap;
    private JTextField massaTxt,  alturaTxt;
    private JLabel massaLabel, alturaLabel, resultado, saude;
    private JButton calcularB, limparB;
    private Double res;

    public IMC()
    {
        makeFrame();
    }

    private void makeFrame()
    {
        hgap = 5;
        vgap = 5;
        frame = new JFrame("Calculando o IMC");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel contentPane = new JPanel();
        contentPane.setOpaque(true);
        contentPane.setBackground(Color.WHITE);
        contentPane.setBorder(BorderFactory.createEmptyBorder(hgap, hgap, hgap, hgap));
        contentPane.setLayout(new BorderLayout(hgap, vgap));

        topPanel = new JPanel();
        topPanel.setOpaque(true);
        topPanel.setBackground(Color.WHITE);
        topPanel.setBorder(BorderFactory.createTitledBorder("Top Panel"));
        topPanel.setLayout(new GridLayout());

        massaTxt = new JTextField(5);
        massaLabel = new JLabel("Massa (Kg): ");
        alturaTxt = new JTextField(5);
        alturaLabel = new JLabel("Altura (m): ");
        resultado = new JLabel("");
        calcularB = new JButton("Calcular");
        limparB = new JButton("Limpar");


        calcularB.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    double peso = Double.parseDouble(massaTxt.getText());
                    double altura = Double.parseDouble(alturaTxt.getText());
                    res = new Double(peso/(altura*altura));
                    res.

                    resultado.setText(res.toString());
                    if(res < 18.5)
                        saude.setText("Magreza");
                    else if(res >= 18.5 && res < 25)
                        saude.setText("Saudável");
                    else if(res >= 25.0 && res < 30)
                        saude.setText("Sobrepeso");
                    else if(res >= 30.0 && res < 35)
                        saude.setText("Obesidade Grau I");
                    else if(res >= 35.0 && res < 40)
                        saude.setText("Obesidade Grau II");
                    else if(res >= 40)
                        saude.setText("Obesidade Grau III");
                    
                }
            }
        );



        limparB.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    resultado.setText("");
                    saude.setText("");
                }
            }
        );

        topPanel.add(massaLabel);
        topPanel.add(massaTxt);
        topPanel.add(alturaLabel);
        topPanel.add(alturaTxt);
        topPanel.add(calcularB);
        topPanel.add(limparB);
        topPanel.add(resultado);

        centerPanel = new JPanel();
        centerPanel.setOpaque(true);
        centerPanel.setBackground(Color.WHITE);
        centerPanel.setBorder(BorderFactory.createTitledBorder("Top Panel"));
        centerPanel.setLayout(new BorderLayout());

        
        saude = new JLabel("\n\n");
        
        centerPanel.add(saude, BorderLayout.CENTER);

        contentPane.add(topPanel, BorderLayout.PAGE_START);
        contentPane.add(centerPanel,BorderLayout.CENTER);


        frame.setContentPane(contentPane);
        frame.pack();
        frame.setLocationByPlatform(true);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        IMC imc = new IMC();
    }

}