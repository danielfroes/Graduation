/**
 * Bank
 */
public class Bank implements BankOperations
{
    public Bank(){}

    public Costumer findCostumer(Costumer[] allCostumer, String cpf)
    {
        for (Costumer costumer : allCostumer)
        {
            if(cpf.equals(costumer.getClientCPF()))
                return costumer;
        }
        return null;   
    }

    public void updateBalance(Costumer[] C, Transition[] M, Bank B)
    {
        for (Transition actualT : M)
        {
            Costumer costumer = B.findCostumer(C, actualT.getCPF());
            if(costumer != null)
                costumer.setBalance(costumer.getBalance() + actualT.getChangeValue());
        }
    }
    

}