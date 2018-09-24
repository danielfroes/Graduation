
/**
 * Mundo Yoshi
 *
 * @author  Pedro Shiguihara
 * @version 1.0  (29 Mar 2012)
 */

class MundoYoshi
{
    private Yoshi objeto1;
    private Yoshi objeto2;
    private Yoshi objeto3;
    private Yoshi objeto4;
    /**
     * Constructor for objects of class MundoYoshi
     */
    public MundoYoshi()
    {
        //objeto1 = new Yoshi("amarelo", 13, 10);
        objeto2 = new Yoshi("vermelho", 0, 1);
        objeto3 = new Yoshi("azul", 4, 7);
        objeto4 = new Yoshi("verde", 0, 0);
    }


    /**
     * Draw this MundoYoshi.
     */
    public void cenario()
    {
        //objeto1.irParaDireita(1);
        //objeto1.irParaCima(4);
        //objeto1.irParaEsquerda(10);

        objeto2.irParaAbaixo(5);
        objeto2.irParaDireita(7);
        objeto2.irParaEsquerda(3);
        objeto2.irParaAbaixo(3);
        objeto2.irParaDireita(4);

        objeto3.irParaEsquerda(3);
        objeto3.irParaAbaixo(5);
        objeto3.irParaDireita(8);
        objeto3.irParaCima(6);

        objeto4.irParaDireita(10);
        objeto4.irParaAbaixo(14);
        objeto4.irParaEsquerda(4);
        objeto4.irParaCima(6);
        objeto4.irParaDireita(4);


        //System.out.println(objeto1.getColor()+","+objeto1.getPosicaoX()+","+objeto1.getPosicaoY());
        System.out.println(objeto2.getColor()+","+objeto2.getPosicaoX()+","+objeto2.getPosicaoY());
        System.out.println(objeto3.getColor()+","+objeto3.getPosicaoX()+","+objeto3.getPosicaoY());
        System.out.println(objeto4.getColor()+","+objeto4.getPosicaoX()+","+objeto4.getPosicaoY());
    }
}

