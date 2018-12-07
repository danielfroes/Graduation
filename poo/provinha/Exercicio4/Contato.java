/**
 * Agenda
 */
public class Contato {
    private String Nome;
    private int idade;
    private String Numero;

    public Contato(String Nome, int idade, String Numero) {
        this.Nome = Nome;
        this.idade = idade;
        this.Numero = Numero;
    }

    public String getNome() {
        return this.Nome;
    }

    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getNumero() {
        return this.Numero;
    }

    public void setNumero(String Numero) {
        this.Numero = Numero;
    }

    
    

}