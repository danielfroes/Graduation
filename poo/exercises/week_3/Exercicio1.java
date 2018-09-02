//Daniel da Rocha Fróes
//10255956
import java.util.Scanner;

public class Exercicio1{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        while(reader.hasNext()){
            String operation = reader.nextLine();
            String[] parts = operation.split(" ");

            if(parts[0].equals("+")){
                System.out.println(Integer.parseInt(parts[1]) + Integer.parseInt(parts[2]));
            }

            else if(parts[0].equals("*")){
                System.out.println(Integer.parseInt(parts[1]) * Integer.parseInt(parts[2]));
            }
        }
    }
}