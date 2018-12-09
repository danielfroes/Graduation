import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import org.jso

import com.sun.org.apache.xerces.internal.impl.xpath.regex.ParseException;

import jdk.nashorn.internal.parser.JSONParser;  

/**
 * Main
 */
public class Main {

    private ArrayList<Materia> readJsonFile(String jsonName)
    {
        JSONParser parser = new JSONParser();
        
        try(FileReader reader = new FileReader (jsonName))
        {
            Object obj = parser.parse(reader);
            

        } catch (FileNotFoundException e){
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e){
            e.printStackTrace();
        }

    }
    public static void main(String[] args) {
        
    }
}