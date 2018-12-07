public class Costumer
{
    private String clienteCPF; // cpf do correntista

    private float balance; // saldo da conta

    public Costumer(String cpf, float balance)
    {
    this.clienteCPF = cpf;
    this.balance = balance;
    }

    public String getClientCPF ()
    {
    return clienteCPF;
    }

    public float getBalance ()
    {
    return balance;
    }

    public void setBalance(float balance)
    {
    this.balance = balance;
    }


}