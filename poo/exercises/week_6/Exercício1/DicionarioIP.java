import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

/**
 * DicionarioIP
 */
public class DicionarioIP {

    
    private HashMap <String, String> dicionario;
    
    


    public DicionarioIP()
    {
        dicionario = new HashMap <String, String>();
    }



    public boolean adicionar(String palavra_ingles, String sinonimo) 
    {
        if (dicionario.containsKey(palavra_ingles))
            return false;
        else
        {
            dicionario.put(palavra_ingles, sinonimo);
            return true;
        }
    }

    public String buscar(String palavra_ingles)
    {
        if(dicionario.containsKey(palavra_ingles))
            return dicionario.get(palavra_ingles);
        
        else
            return "";
    
    }

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