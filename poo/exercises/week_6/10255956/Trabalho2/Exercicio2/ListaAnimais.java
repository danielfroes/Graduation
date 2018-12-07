import java.util.ArrayList;

/**
 * ListaAnimais
 */
public class ListaAnimais
{
    public void listar(ArrayList<Animal> lAnimais)
    {
        for (Animal animal : lAnimais)
        {
            animal.info();
        }
    }
}