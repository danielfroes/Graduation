//Daniel Fróes
//10255956

import java.util.Scanner;

public class Exercicio1{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String expression = reader.nextLine();
        
        for(int i = 0; i < expression.length() ; i ++){
            if(expression.charAt(i) == '+')
                System.out.println("S");
            else if(expression.charAt(i) == '*')
                System.out.println("M");
        }
    }
}