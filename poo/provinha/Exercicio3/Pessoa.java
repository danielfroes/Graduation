import java.sql.Date;

/**
 * Pessoa
 */
public class Pessoa 
{
    private String nome;
    private String nusp;
    private Date dataIngresso;


	public Pessoa(String nome, String nusp, Date dataIngresso) {
		this.nome = nome;
		this.nusp = nusp;
		this.dataIngresso = dataIngresso;
	}

	public String getNome() {
		return this.nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getNusp() {
		return this.nusp;
	}

	public void setNusp(String nusp) {
		this.nusp = nusp;
	}

	public Date getDataIngresso() {
 		return this.dataIngresso;
	}

	public void setDataIngresso(Date dataIngresso) {
		this.dataIngresso = dataIngresso;
	}

	// @Override
    // public int compareTo(Pessoa o) {
    //   return getDataIngresso().compareTo(o.getDataIngresso());
    // }
}