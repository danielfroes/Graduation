/**
 * Baleia
 */
public class Baleia extends Animal
{
    private double alturaMaximaSalto;
    private double sinalInfrasonica;

    public Baleia(String apelido, int idade, double peso, String descricao ,double alturaMaximaSalto, double sinalInfrasonica)
    {
        super(apelido, idade, peso, descricao);
        this.alturaMaximaSalto = alturaMaximaSalto;
        this.sinalInfrasonica = sinalInfrasonica;
    }

    public void info()
    {
        super.info();
        System.out.println("Salto:"+alturaMaximaSalto);
        System.out.println("Sonido:"+sinalInfrasonica);
    }
}