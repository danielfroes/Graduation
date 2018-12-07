/**
 * Aguia
 */
public class Aguia extends Animal
{
    private double envergadura;
    private double elevacaoMaxima;

    public Aguia(String apelido, int idade, double peso, String descricao, double envergadura, double elevacaoMaxima)
    {
        super(apelido, idade, peso, descricao);
        this.envergadura = envergadura;
        this.elevacaoMaxima = elevacaoMaxima;
    }

    public void info()
    {
        super.info();
        System.out.println("Envergadura:"+envergadura);
        System.out.println("Elevacao:"+elevacaoMaxima);
    }
    
}