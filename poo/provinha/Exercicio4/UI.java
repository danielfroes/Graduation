import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.BorderFactory;

/**
 * UI
 */
public class UI {
    private Agenda agenda;
    private JFrame frame;
    private JButton adicionar, remover, editar, pesquisar;
    private JTextField nome, idade, numero;
    private JPanel westPanel, eastPanel, bottomPanel;
    private JLabel nomeL, idadeL, numeroL;


    public UI()
    {
        agenda = new Agenda();
        makeframe(agenda);
    }

    public void makeframe(Agenda agenda)
    {

        frame = new JFrame("Agenda");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel contentPane = new JPanel();
        contentPane.setOpaque(true);
        contentPane.setBackground(Color.WHITE);
        contentPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(5, 5));

        westPanel = new JPanel();
        westPanel.setOpaque(true);
        westPanel.setBackground(Color.WHITE);
        westPanel.setBorder(BorderFactory.createTitledBorder("West Panel"));
        westPanel.setLayout(new GridLayout(3, 2));
        
        nomeL = new JLabel("Nome : ");
        nome = new JTextField(20);
        idadeL = new JLabel("Idade : ");
        idade = new JTextField(3);
        numeroL = new JLabel("Numero : ");
        numero = new JTextField(11);


        westPanel.add(nomeL);
        westPanel.add(nome);
        westPanel.add(idadeL);
        westPanel.add(idade);
        westPanel.add(numeroL);
        westPanel.add(numero);

        eastPanel = new JPanel();
        eastPanel.setOpaque(true);
        eastPanel.setBackground(Color.WHITE);
        eastPanel.setBorder(BorderFactory.createTitledBorder("East Panel"));
        eastPanel.setLayout(new BoxLayout(eastPanel, BoxLayout.Y_AXIS));

        eastPanel.add( new JLabel("                                                  "));

        bottomPanel = new JPanel();
        bottomPanel.setOpaque(true);
        bottomPanel.setBackground(Color.WHITE);
        bottomPanel.setBorder(BorderFactory.createTitledBorder("Bottom Panel"));
        bottomPanel.setLayout(new FlowLayout());

        adicionar = new JButton("Adicionar");
        adicionar.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    agenda.adicionarContato(nome.getText(), Integer.valueOf(idade.getText()), numero.getText());
                    UpdateContactsUI(agenda, eastPanel);
                }
            }
        );
        bottomPanel.add(adicionar);
        
        remover = new JButton("Remover");
        remover.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    agenda.removerContato(nome.getText());
                    UpdateContactsUI(agenda, eastPanel);
                }
            }
        );
        bottomPanel.add(remover);

        

        pesquisar = new JButton("Pesquisar");
        pesquisar.addActionListener(
            new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    if(agenda.buscar(nome.getText()))
                    {
                        eastPanel.setVisible(false);
                        eastPanel.add(new JLabel("ACHOU!!"));
                        eastPanel.setVisible(true);
                    }
                    else{
                        eastPanel.setVisible(false);
                        eastPanel.add(new JLabel("NÃO ACHOU"));
                        eastPanel.setVisible(true);
                    }
                }
            }
        );
        bottomPanel.add(pesquisar);

        editar = new JButton("Editar");
        editar.addActionListener(
            new ActionListener(){
                public void actionPerformed(ActionEvent e)
                {
                   agenda.editarContato(nome.getText(), Integer.valueOf(idade.getText()), numero.getText());
                   UpdateContactsUI(agenda, eastPanel);
                }
            }
        );
        bottomPanel.add(editar);
        
        contentPane.add(westPanel, BorderLayout.WEST);
        contentPane.add(eastPanel, BorderLayout.EAST);
        contentPane.add(bottomPanel, BorderLayout.SOUTH);

        frame.setContentPane(contentPane);
        frame.pack();
        frame.setLocationByPlatform(true);
        frame.setVisible(true);
    }

    private void UpdateContactsUI(Agenda agenda,JPanel eastPanel)
    {
        eastPanel.removeAll();
        eastPanel.setVisible(false);
        if(agenda.getContatos().isEmpty())
        {
            eastPanel.add( new JLabel("                                                  "));
        }
        else{
            for (Contato c : agenda.getContatos())
            {
                eastPanel.add(new JLabel(c.getNome() + " " + c.getIdade() + " " + c.getNumero()));
            }
        }
        
        eastPanel.setVisible(true);
    }

    public static void main(String[] args) {
        UI ui = new UI();
    }
}