//Daniel Fróes
//10255956

import java.util.Scanner;

public class Exercicio2{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String email_list = reader.nextLine();  
        String[] email = email_list.split(",");
        for (int i = 0 ; i < email.length ; i++){
            String name = email[i].substring(0,email[i].indexOf('@'));
            System.out.println(name);
        }
    }
}