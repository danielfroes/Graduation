/**
 * Animal
 */
public class Animal
{
   private String apelido;
   private int idade;
   private double peso;
   private String descricao;

   public Animal(String apelido, int idade, double peso, String descricao)
   {
        this.apelido = apelido;
        this.idade = idade;
        this.peso = peso;
        this.descricao = descricao;
   }

   public void infoGeral()
   {
        System.out.println("Nome:"+apelido+"_Idade:"+idade+"_Peso:"+peso+"_Descricao:"+descricao);
   }

   public void info()
   {
        System.out.println("Nome:"+apelido);
        System.out.println("Idade:"+idade);
        System.out.println("Peso:"+peso);
        System.out.println("Descricao:"+descricao);
   }
}