import java.time.LocalTime;

public class Horario
{
    private LocalTime horarioInicio;
    private LocalTime horarioFinal;
    private String diaDaSemana;

    public Horario(String horarioInicio,String horarioFinal, String diaDaSemana) {
        this.horarioInicio = LocalTime.parse(horarioInicio);
        this.horarioFinal = LocalTime.parse(horarioFinal);
        this.diaDaSemana = diaDaSemana;
    }

    public LocalTime getHorarioInicio() {
        return this.horarioInicio;
    }

    public void setHorarioInicio(LocalTime horarioInicio) {
        this.horarioInicio = horarioInicio;
    }

    public LocalTime getHorarioFinal() {
        return this.horarioFinal;
    }

    public void setHorarioFinal(LocalTime horarioFinal) {
        this.horarioFinal = horarioFinal;
    }

    public String getDiaDaSemana() {
        return this.diaDaSemana;
    }

    public void setDiaDaSemana(String diaDaSemana) {
        this.diaDaSemana = diaDaSemana;
    }

    @Override
    public String toString() {
        return "{" +
            " horarioInicio='" + getHorarioInicio() + "'" +
            ", horarioFinal='" + getHorarioFinal() + "'" +
            ", diaDaSemana='" + getDiaDaSemana() + "'" +
            "}";
    }
}
