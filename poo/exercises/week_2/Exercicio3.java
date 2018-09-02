//Daniel Fróes
//10255956
import java.util.Scanner;

public class Exercicio3{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String phrase = reader.nextLine();
        char separator = reader.nextLine().charAt(0);
        int word_cnt = 1; //initialize the variable with 1 to already count the last word
        for (int i = 0 ; i < phrase.length() ; i++){  
            if(phrase.charAt(i) == separator)
                word_cnt++;
        }

        String[] words = new String[word_cnt];
        int init = 0;
        for(int i = 0, j = 0; i < phrase.length() ; i++){
            
            if(phrase.charAt(i) == separator){
                words[j] = phrase.substring(init,i);
                j++;
                init = i+1;
            }
            if(j == word_cnt - 1){
                words[j] = phrase.substring(init);
            }
        }

        for(String word:words){
            System.out.println(word);
        }
    }
}