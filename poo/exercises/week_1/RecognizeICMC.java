import java.util.Scanner;

public class RecognizeICMC {

    public static boolean recognize(String word){
        if(word.equals("ICMC-USP")){
            return true;
        }
        else{
            return false;
        }
    }
    
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String word = reader.next();
       
        if(recognize(word)){
            System.out.println("reconhecido");
        }
        else{
            System.out.println("errado");
        }
    }

}