import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;



public class Exercicio3 
{
    public class Dicionario
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
    }

    public class DicionarioSimples extends Dicionario
    {   
      
        
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
    public class DicionarioIp extends Dicionario
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

    public static void main(String[] args)
    {
        DicionarioIp dic1 = new Dicionario();
        DicionarioSimples dic2 = new DicionarioSimples();
    
        dic1.adicionar("cat", "gato felino");
        dic2.adicionar("gato", "é um animal");
        dic2.adicionar("urso", "giria gay");

        dic1.mostrarTodo();
        dic2.mostrarTodo();
    }
}