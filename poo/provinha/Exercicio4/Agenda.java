import java.util.ArrayList;

import jdk.nashorn.internal.runtime.linker.BoundCallable;

/**
 * Agenda
 */
public class Agenda{

    private ArrayList<Contato> contatos = new ArrayList<Contato>();

    public ArrayList<Contato> getContatos() {
        return this.contatos;
    }

    public void setContatos(ArrayList<Contato> contatos) {
        this.contatos = contatos;
    }

    public void adicionarContato(String nome, int idade, String nsumero)
    {
        contatos.add(new Contato(nome, idade, nsumero));
    } 

    public void removerContato(String nome)
    {
        for (Contato c : contatos)
        {   
            if(c.getNome().equals(nome))
                contatos.remove(c);
        }
    }

    public boolean buscar(String nome)
    {
        for(Contato c : contatos)
        {
            if(c.getNome().equals(nome))
            {
               
                return true;
            }                
        }
        return false;
    }

    public void printarTudo()
    {
        for(Contato c : contatos)
        {
            System.out.println(c.getNome() + " " + c.getIdade() + " " + c.getNumero());
        }
    }

    public void printaNome(String nome)
    {

        for(Contato c : contatos)
        {
            if(c.getNome().equals(nome))
                System.out.println(c.getNome() + " " + c.getIdade() + " " + c.getNumero());
        }
    }

    public void editarContato(String nome, int idade, String numero)
    {
        for(Contato c : contatos)
        {
            if(c.getNome().equals(nome))
            {
                c.setIdade(idade);
                c.setNumero(numero);
            }
        }
    }
}