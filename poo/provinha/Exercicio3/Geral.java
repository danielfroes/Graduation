/**
 * Geral
 */
public class Geral extends Funcionario {

    private String funcao;
    private boolean ferias;

    public Geral(String nome, String nusp, Date dataIngresso, double salario, int anos, String funcao, boolean ferias) {
        super(nome, nusp, dataIngresso, salario, anos);
        this.funcao = funcao;
        this.ferias = ferias;
    }

    public String getFuncao() {
        return this.funcao;
    }

    public void setFuncao(String funcao) {
        this.funcao = funcao;
    }

    public boolean GetFerias() {
        return this.ferias;
    }

    public void setFerias(boolean ferias) {
        this.ferias = ferias;
    }

    
    
}