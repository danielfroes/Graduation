import java.util.Scanner;

public class Printer{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String word;
        do{
            word = reader.nextLine();
            System.out.println(word);
        }while(!word.equals("fim"));
    }
}