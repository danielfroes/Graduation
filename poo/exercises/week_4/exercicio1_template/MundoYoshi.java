
/**
 * Mundo Yoshi
 *
 * @author  Pedro Shiguihara
 * @version 1.0  (29 Mar 2012)
 */

class MundoYoshi
{
    private Yoshi yoshi1;

    /**
     * Constructor for objects of class MundoYoshi
     */
    public MundoYoshi()
    {
        yoshi1 = new Yoshi();
        yoshi1.setIsShowed(true);
    }


    /**
     * Draw this MundoYoshi.
     */
    public void cenario(){
        yoshi1.setColor("verde");
        yoshi1.irParaBaixo(3);
        yoshi1.irParaBaixo(5);
        System.out.println(yoshi1.getColor()+","+yoshi1.getPosicaoX()+","+yoshi1.getPosicaoY());
    }

   
}

