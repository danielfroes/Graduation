/**
 * Aluno
 */
public class Aluno extends Pessoa {

    private String curso;
    private int periodo;
    private ArrayList<String> dps;
    private Date previsaoDeFormatura;

    public Aluno(String nome, String nusp, Date dataIngresso,String curso, int periodo, ArrayList<String> dps, Date previsaoDeFormatura) {
        super(nome, nusp, dataIngresso);
        this.curso = curso;
        this.periodo = periodo;
        this.dps = dps;
        this.previsaoDeFormatura = previsaoDeFormatura;
    }

    
    public String getCurso() {
        return this.curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public int getPeriodo() {
        return this.periodo;
    }

    public void setPeriodo(int periodo) {
        this.periodo = periodo;
    }

    public ArrayList<String> getDps() {
        return this.dps;
    }

    public void setDps(ArrayList<String> dps) {
        this.dps = dps;
    }

    public Date getPrevisaoDeFormatura() {
        return this.previsaoDeFormatura;
    }

    public void setPrevisaoDeFormatura(Date previsaoDeFormatura) {
        this.previsaoDeFormatura = previsaoDeFormatura;
    }

}