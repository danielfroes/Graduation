import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

public class BancoDicionarios
{
    private ArrayList<Dicionario> bancoDicionarios;


    public BancoDicionarios() 
    {
        bancoDicionarios = new ArrayList<Dicionario>();
    }

    public boolean adicionarDicionario(Dicionario dic) 
    {
        bancoDicionarios.add(dic);
        if(bancoDicionarios.contains(dic))
            return true;
        else
            return false;
    }

    public void mostrarConteudoDicionarios() 
    {
        for(Dicionario dic: bancoDicionarios)
            dic.mostrarTodo();
    }

    public static void main(String[] args) {
        BancoDicionarios teste = new BancoDicionarios();
        DicionarioIp dicTeste = new DicionarioIp();
        DicionarioSimples dicTeste2 = new DicionarioSimples();
        
        dicTeste.adicionar("cellphone", "celular telefone");
        dicTeste2.adicionar("lala", "blablabla zazaza");
        dicTeste.adicionar("hello", "ola oi");
       

        teste.adicionarDicionario(dicTeste);
        teste.adicionarDicionario(dicTeste2);
        
        teste.mostrarConteudoDicionarios();

    }
}

abstract class Dicionario
{
    protected HashMap<String, String> dicionario;

    public Dicionario()
    {
        dicionario = new HashMap<String, String>();
    }

    public boolean adicionar(String chave, String dado) 
    {
        if (dicionario.containsKey(chave))
            return false;
        else
        {
            dicionario.put(chave, dado);
            return true;
        }
    }

    public String buscar(String chave)
    {
        if(dicionario.containsKey(chave))
            return dicionario.get(chave);
        else
            return "";
    
    }
    
    abstract void mostrarTodo();

}

class DicionarioSimples extends Dicionario
{      
    public DicionarioSimples()
    {
        super();
    }
    public void mostrarTodo()
    {
        Set <String> palavras = dicionario.keySet();

        for(Iterator it = palavras.iterator(); it.hasNext();)
        {
            String palavra = (String) it.next();
            String significado = dicionario.get(palavra);
            System.out.println(palavra + ":" + significado);
        }
    }
}

/**
 * DicionarioIp
*/
class DicionarioIp extends Dicionario
{ 
    public void mostrarTodo()
    {
        Set <String> palavras_ingles = dicionario.keySet();

        for(Iterator it = palavras_ingles.iterator(); it.hasNext();)
        {
            String palavra_ingles = (String) it.next();
            String sinonimo = dicionario.get(palavra_ingles);
            sinonimo = sinonimo.replaceAll(" ", ",");
            System.out.println(palavra_ingles + ":" + sinonimo);
        }
    }

}