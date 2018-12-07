/**
 * Main
 */
public class Main {
    public static void main(String[] args) {
        Costumer[] C = {new Costumer("1", 10f), new Costumer("2", 20f), new Costumer("3", 30f)};
        Transition[] M = {new Transition("1", -5f), new Transition("2", 5f), new Transition("3",-4.5f), new Transition("1", 3.5f)};
        Bank B = new Bank();

        B.updateBalance(C, M, B);

        for(Costumer costumer : C)
            System.out.println(costumer.getClientCPF() + " > " + costumer.getBalance());
    }
}