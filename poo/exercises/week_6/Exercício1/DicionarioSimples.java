import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;


public class DicionarioSimples
{
    private HashMap <String, String> dicionario;
    
    


    public DicionarioSimples()
    {
        dicionario = new HashMap <String, String>();
    }



    public boolean adicionar(String palavra, String significado) 
    {
        if (dicionario.containsKey(palavra))
            return false;
        else
        {
           dicionario.put(palavra, significado);
           return true;
        }
    }

    public String buscar(String palavra)
    {
        if(dicionario.containsKey(palavra))
            return dicionario.get(palavra);
        
        else
            return "";
    
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