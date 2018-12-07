/**
 * Programa GUI
 * 
 * @author Pedro Shiguihara
 * @version 1.0
 */
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Programa1
{
    //Campos
    private JFrame quadro;
    
    private JLabel rotulo;
    private JTextField campoTexto;
    private JButton botonReconhecer;
    
    //Construtor
    public Programa1(){
        this.criarQuadro();
    }
    
    ////////////// QUADRO /////////////////////////
    //Criar quadro
    private void criarQuadro(){
        quadro = new JFrame( "Reconhecedor GUI" );
                
        campoTexto = new JTextField(20);
        
        botonReconhecer = new JButton( "Reconhecer" );
        botonReconhecer.addActionListener(new ReconhecedorActionListener());
        
        rotulo = new JLabel( "Resultado:" );
        
        quadro.setLayout( new FlowLayout() );
        quadro.add(campoTexto);
        quadro.add(botonReconhecer);
        quadro.add(rotulo);
        
        quadro.setSize(200, 100);
        quadro.setVisible(true);
    }
    
    //Classe interna ouvinte para o botão "botonReconhecer" e Reconhecedor
    class ReconhecedorActionListener implements ActionListener {
        public void actionPerformed(ActionEvent event){
            String texto = campoTexto.getText();
            if( texto.equals("ICMC-USP") ) {
                rotulo.setText( "Resultado: Reconhecido" );
            } else {
                rotulo.setText( "Resultado: Nao reconhecido" );
            }
        }
    }
    
    
    
}
