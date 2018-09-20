
/**
 * Yoshi
 *
 * @author  Pedro Shiguihara
 * @version 1.0  (29 Mar 2012)
 */
class Yoshi
{
    private int posicao_x;
    private int posicao_y;
    private String color;
    private String direcao;

	private Boolean isShowed;

    /**
     * Cria um objeto com posicao, color e direcao por default
     */
    public Yoshi() {
        posicao_x=0;
        posicao_y=0;
        color = "verde";
        direcao = "acima";
        isShowed = true;
    }

    public void setIsShowed(Boolean isShowed){
    	this.isShowed = isShowed;
    }

    /**
     * Captura o color
     */
    public String getColor(){
        return color;
    }

    /**
     * Modifica o color
     */
    public void setColor(String color){
        this.color = color;
    }

    /**
     * Retorna posicao no eixo X
     */
    public int getPosicaoX(){
        return posicao_x;
    }

    /**
     * Retorna posicao no eixo Y
     */
    public int getPosicaoY(){
        return posicao_y;
    }


    /**
     * Mover para abaixo
     */
    public void irParaEsquerda(int distancia){
        this.posicao_x -= distancia;
    }
    public void irParaCima(int distancia){
        this.posicao_y += distancia;
    }
    public void irParaDireita(int distancia){
        this.posicao_x += distancia;
    }
    public void irParaBaixo(int distancia){
        this.posicao_y -= distancia;
    }


    /**
     * Visualiza objeto no Canvas
     */
    private void visualizar(){
		if( isShowed == true ){
			Canvas canvas = Canvas.getCanvas();
	        canvas.drawImage(this,posicao_x,posicao_y);
	        canvas.wait(10);
	    }
    }
}
