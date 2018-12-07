/**
 * Guepardo
 */
public class Guepardo extends Animal
{
    private double velocidadeCorrida;

    public Guepardo(String apelido, int idade, double peso, String descricao,double velocidadeCorrida)
    {
        super(apelido, idade, peso, descricao);
        this.velocidadeCorrida = velocidadeCorrida;
    }

    public void info()
    {
        super.info();
        System.out.println("Velocidade:"+velocidadeCorrida);
    }
}