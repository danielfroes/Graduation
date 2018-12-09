import java.util.ArrayList;
import java.time.LocalTime;

/**
 * classe1
 */
public class Materia
{
    private String nome;  
    private int creditos;
    private int periodo;
    private boolean completa;
    private ArrayList<Horario> horarios;
    private ArrayList<String> requisitos;

    

    public Materia(String nome, ArrayList<Horario> horarios, int creditos,int periodo, boolean completa, ArrayList<String> requisitos) {
        this.nome = nome;
        this.horarios = horarios;
        this.periodo = periodo;
        this.creditos = creditos;
        this.completa = completa;
        this.requisitos = requisitos;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public ArrayList<Horario> getHorarios() {
        return this.horarios;
    }

    public void setHorarios(ArrayList<Horario> horarios) {
        this.horarios = horarios;
    }

    public int getCreditos() {
        return this.creditos;
    }

    public void setCreditos(int creditos) {
        this.creditos = creditos;
    }

    public int getPeriodo() {
        return this.periodo;
    }

    public void setPeriodo(int periodo) {
        this.periodo = periodo;
    }

    public boolean isCompleta() {
        return this.completa;
    }

    public void setCompleta(boolean completa) {
        this.completa = completa;
    }

    public ArrayList<String> getRequisitos() {
        return this.requisitos;
    }

    public void setRequisitos(ArrayList<String> requisitos) {
        this.requisitos = requisitos;
    }
    @Override
    public String toString() {
        return "{" +
            " nome='" + getNome() + "'" +
            ", creditos='" + getCreditos() + "'" +
            ", periodo='" + getPeriodo() + "'" +
            ", completa='" + isCompleta() + "'" +
            ", horarios='" + getHorarios() + "'" +
            ", requisitos='" + getRequisitos() + "'" +
            "}";
    }

}