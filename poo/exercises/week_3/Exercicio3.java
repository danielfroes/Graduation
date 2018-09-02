//Daniel da Rocha Fróes
//10255956
import java.util.Scanner;

public class Exercicio3{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        while(reader.hasNext()){
            String operation = reader.nextLine();
            String[] parts = operation.split(" ");

            if(parts[2].equals("+")){
                System.out.println(Integer.parseInt(parts[0]) + Integer.parseInt(parts[1]));
            }

            else if(parts[2].equals("*")){
                System.out.println(Integer.parseInt(parts[0]) * Integer.parseInt(parts[1]));
            }
        }
    }
}