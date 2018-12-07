/**
 * ActiveCustumer
 */
public class Transition implements AccountChange
{
    private float changeValue;
    private String cpf;
    
    public Transition(String cpf, float changeValue)
    {
        this.cpf = cpf;
        this.changeValue = changeValue;
    }

    public String getCPF()
    {
        return cpf;
    }

    public float getChangeValue()
    {
        return changeValue;
    }
    
}