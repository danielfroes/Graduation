//Daniel Fróes
//10255956
import java.util.Scanner;

public class Exercicio2{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String expression = reader.nextLine();

        for(int i = 0; i < expression.length() ; i++){
            if(expression.charAt(i) == '+')
                System.out.println("S");
            else if(expression.charAt(i) == '*')
                System.out.println("M");
        }

        for(int i = 0; i < expression.length() ; i++){
            if(expression.charAt(i) == '+' || expression.charAt(i) == '*')
                System.out.printf("%d ",Integer.parseInt(expression.substring(i-1,i)));
            if(i == expression.length()-1)
                System.out.printf("%d\n",Integer.parseInt(expression.substring(i)));
        }
    }
}