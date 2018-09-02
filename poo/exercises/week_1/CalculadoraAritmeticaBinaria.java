import java.util.Scanner;

public class CalculadoraAritmeticaBinaria{
   
    public static int soma(int resultado,int num){
        resultado = resultado + num;
        return resultado;
    }
    
    
    public static void main(String[] args) {
        int resultado = 0; 
        Scanner reader = new Scanner(System.in);
        String entry;
        int num;
        int ctrl = 0;
        while(ctrl == 0){
            entry = reader.nextLine();

            if(entry.equals("=")){
                ctrl = 1;
                break;
            }
            num = Integer.parseInt(entry);
            resultado = soma(resultado,num);
        }
    
        System.out.println(resultado);
    }
}