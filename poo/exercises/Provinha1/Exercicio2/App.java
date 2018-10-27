import java.math.BigInteger;
import java.util.Scanner;
import java.util.HashMap;
/**
 * App
 */
public class App {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        long number; 
        do{
            number = reader.nextLong();
            UnsignedInteger unsNumber = new UnsignedInteger(number);
        
            unsNumber.printNumber(unsNumber.fatorial());
        }while(number != -1);    
    }

    public static class UnsignedInteger{
        private BigInteger number;
        private HashMap<Integer ,BigInteger> results;
    
        public UnsignedInteger(long number){
            this.number = BigInteger.valueOf(number);
            this.results = new HashMap<Integer, BigInteger>();
        }

        public void printNumber(BigInteger n) {
            System.out.println("o Numero é: " + n);
        }

        public BigInteger fatorial(){
            BigInteger res =  BigInteger.ONE;
            for(BigInteger n = this.number; n.compareTo(BigInteger.ONE) >= 0; n = n.subtract(BigInteger.ONE)){

                if(results.get(Integer.valueOf(n.intValue())) != null){
                    return res.multiply(results.get(Integer.valueOf(n.intValue())));
                }
                else
                    res = res.multiply(n); 

            }
            return res;
        }
    }
}

