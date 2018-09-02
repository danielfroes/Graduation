//Daniel Fróes
//10255956
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Exercicio4{
  public static void main(String[] args) throws FileNotFoundException{

    File file = new File("test.txt");
    Scanner reader_file = new Scanner(file); 
    Scanner reader_kb = new Scanner(System.in);
    char separator = reader_kb.nextLine().charAt(0);

    while(reader_file.hasNextLine()){

      String phrase = reader_file.nextLine();
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

      for(String word:words)
        System.out.println(word);
    
    }
  }
}