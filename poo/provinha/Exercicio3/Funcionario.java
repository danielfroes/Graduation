/**
 * Funcionario
 */
public class Funcionario extends Pessoa {
    private double salario;
    private int anos;
 
    public Funcionario(String nome, String nusp, Date dataIngresso, double salario, int anos) {
        super(nome, nusp, dataIngresso);
        this.salario = salario;
        this.anos = anos;
    }

    public double getSalario() {
        return this.salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public int getAnos() {
        return this.anos;
    }

    public void setAnos(int anos) {
        this.anos = anos;
    }

    public void ajusteSalarial(double percent){
        setSalario(getSalario()*(percent/100));
    }
    
}  