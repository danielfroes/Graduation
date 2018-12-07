/**
 * Professor
 */
public class Professor extends Funcionario {

    private String titulo;
    private String departamento;
    private String sala;
    private String especialidade;


    public Professor(String nome, String nusp, Date dataIngresso, double salario, int anos, String titulo, String departamento, String sala, String especialidade) {
        super(nome, nusp, dataIngresso, salario, anos);
        this.titulo = titulo;
        this.departamento = departamento;
        this.sala = sala;
        this.especialidade = especialidade;
    }

    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getDepartamento() {
        return this.departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public String getSala() {
        return this.sala;
    }

    public void setSala(String sala) {
        this.sala = sala;
    }

    public String getEspecialidade() {
        return this.especialidade;
    }

    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

}