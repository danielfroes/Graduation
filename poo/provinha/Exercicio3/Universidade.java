import java.sql.Date;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.time;

/**
 * Universidade
 */
public interface GerenciadorDePessoas{
    public void ordenarDataIngresso(); // dificil pra krl trabalhar com esse classe Data
    public void areasSemelhantes(); //se nao retorna nada pra que serve esse negocio?
    //public int emFerias();// nao faço ideia do que isso faz
    public ArrayList<Pessoa> emFerias();
    //public ArrayList<Pessoa> jubilados();
    //public boolean periodoIdeal(String id);
}

public class Universidade implements GerenciadorDePessoas {

    private ArrayList <Pessoa> ligadosUniversidade;
    
    public Universidade(){
        ligadosUniversidade = new ArrayList<Pessoa>();
    }
    public void adicionarPessoa(Pessoa pessoa){
        ligadosUniversidade.add(pessoa);
    }
    public void removerPessoa(Pessoa pessoa){
        ligadosUniversidade.remove(pessoa);
    }

    public void editarPessoa(Pessoa pessoa){
        Scanner reader  = new Scanner();
            
        System.out.println("nome: ");
        String nome = reader.nextLine();
        if(nome != "");
           pessoa.setNome(nome);
        
        System.out.println("nusp: ");
        String nusp = reader.nextLine();
        if(nusp != "");
           pessoa.setNusp(nusp);
        
        System.out.println("Data de ingresso: ");
        String dataIngresso = reader.nextLine();
        if(dataIngresso  != "")
           pessoa.setDataIngresso(new Date(Long.valueOf(dataIngresso)));
        
        if(pessoa instanceof Aluno)
        {
            System.out.println("Curso: ");
            String curso = reader.nextLine();
            if(dataIngresso  != "")
                ((Aluno)pessoa).setCurso(curso);

            System.out.println("Periodo: ");
            int period = reader.nextInt();
            if(dataIngresso  != "")
                ((Aluno)pessoa).setCurso(curso);


            System.out.println("Previsão de Formatura: ");
            String previsaoDeFormatura = reader.nextLine();
            if(dataIngresso  != "")
                ((Aluno)pessoa).setDataIngresso(new Date(Long.valueOf(previsaoDeFormatura)));

            
            // System.out.println("dps: ");
            // String dps = reader.nextLong();
            // if(dataIngresso  != "")
            // {
            //     ArrayList<String> strList = new ArrayList<String>()
            //     dps.split(" ");

            //     ((Aluno)pessoa).setCurso();
            // }
        }
    }

    public void ordenarDataIngresso(){
        ligadosUniversidade.sort(Comparator.comparing(Pessoa::getDataIngresso));
    } 


    public void areasSemelhantes()
    {  
        ArrayList<Professor> profs = new ArrayList<Professor>();
        for (Pessoa p : ligadosUniversidade)
        {
            if(p instanceof Professor)
                profs.add((Professor)p);
        }
        ArrayList<String> area = new ArrayList<String>();
        for (Professor prof : profs)
        {
            if(!area.contains(prof.getEspecialidade()))
            {
               area.add(prof.getEspecialidade());
            }
        }
        for (String A : area)
        {
            System.out.println(A+" :");
            for (Professor prof : profs)
            {
                if(A.equals(prof.getEspecialidade()))
                {
                    System.out.print(((Pessoa)prof).getNome() + " ");
                }
            }
            System.out.println();
        }
    }

    public int emFerias1()
    {
        int cnt;
        for (Pessoa p : ligadosUniversidade)
        {
            if(p instanceof Geral)
            {
                if(((Geral)p).GetFerias())
                    cnt++;
            }
        }

        return cnt;
    }

    public ArrayList<Pessoa> emFerias2()
    {
        ArrayList<Geral> gerais = new ArrayList<Geral>();
        for (Pessoa p : ligadosUniversidade)
        {
            if(p instanceof Geral)
            {
                if(((Geral)p).GetFerias())
                    gerais.add((Geral)p);
            }
        }
        return gerais;
    }

    public ArrayList<Pessoa> jubilados()
    {   
        ArrayList<Aluno> jubilados = new ArrayList<Pessoa>();
        for (Pessoa p : ligadosUniversidade)
        {
            if(p instanceof Aluno)
            {
                if( (p.getDataIngresso().getYear() - ((Aluno)p).getPrevisaoDeFormatura().getYear()) < (((Aluno)p).getDps().size()*3));
                {
                    jubilados.add((Aluno)p);
                }
            }
        }
    }

    public bool periodoIdeal(String id)
    {
        for(Pessoa p : ligadosUniversidade)
        {
            if(p instanceof Aluno)
            {
                int anos = p.getDataIngresso().getYear() - ((Aluno)p).getPrevisaoDeFormatura().getYear();
                int dps = p.getDps().size();
                if(p.getNusp() == id)
                {
                    if(anos > 0)
                    {
                        return false;
                    }
                    if(dps > anos)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }


    public static void main(String[] args)
    {
        Universidade u = new Universidade();
        Pessoa p1 = new Professor("Dilvan", "1", new Date(Random.nextlong()), 23, "mestrado" , "ICMC", "4-233",  "Desenvolvimento Web");
        u.adicionarPessoa(pessoa);
    }

}