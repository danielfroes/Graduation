/**
 * Canvas is a class to allow for simple graphical drawing on a canvas.
 * This is a modification of the general purpose Canvas.
 * Modified by Pedro Shiguihara on 03/29/2012. Oriented-Object Programming Course - ICMC - USP.
 *
 * @author: Bruce Quig
 * @author: Michael Kolling (mik)
 *
 * @version: 1.6 (shapes)
 */
import javax.swing.*;
import java.awt.*;
import java.util.List;
import java.util.*;
import java.awt.geom.AffineTransform;
import java.awt.Image;
import javax.swing.ImageIcon;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;

class Canvas
{
    // Note: The implementation of this class (specifically the handling of
    // shape identity and colors) is slightly more complex than necessary. This
    // is done on purpose to keep the interface and instance fields of the
    // shape objects in this project clean and simple for educational purposes.

    private static Canvas canvasSingleton;
    private static ImageIO imageIO;

    /**
     * Factory method to get the canvas singleton object.
     */
    public static Canvas getCanvas()
    {
        if(canvasSingleton == null) {
            canvasSingleton = new Canvas("Mundo da Yoshi", 300, 300,
                    Color.white);
        }
        canvasSingleton.setVisible(true);
        return canvasSingleton;
    }

    //  ----- instance part -----

    private JFrame frame;
    private CanvasPane canvas;
    private Graphics2D graphic;
    private Color backgroundColour;
    private Image canvasImage;
    private List objects;
    private HashMap shapes;
    private static AffineTransform transformer;
    private BufferedImage bufferedImage; // Image itself

    private List objetos;
    private HashMap coordenadasObjetos;

    /**
     * Create a Canvas.
     * @param title  title to appear in Canvas Frame
     * @param width  the desired width for the canvas
     * @param height  the desired height for the canvas
     * @param bgClour  the desired background colour of the canvas
     */
    private Canvas(String title, int width, int height, Color bgColour)
    {
        frame = new JFrame();
        canvas = new CanvasPane();
        frame.setContentPane(canvas);
        frame.setTitle(title);
        canvas.setPreferredSize(new Dimension(width, height));
        backgroundColour = bgColour;
        frame.pack();
        objects = new ArrayList();
        shapes = new HashMap();
        objetos = new ArrayList();
        coordenadasObjetos = new HashMap();
    }

    /**
     * Set the canvas visibility and brings canvas to the front of screen
     * when made visible. This method can also be used to bring an already
     * visible canvas to the front of other windows.
     * @param visible  boolean value representing the desired visibility of
     * the canvas (true or false)
     */
    public void setVisible(boolean visible)
    {
        if(graphic == null) {
            // first time: instantiate the offscreen image and fill it with
            // the background colour
            Dimension size = canvas.getSize();
            canvasImage = canvas.createImage(size.width, size.height);
            graphic = (Graphics2D)canvasImage.getGraphics();
            graphic.setColor(backgroundColour);
            graphic.fillRect(0, 0, size.width, size.height);
            graphic.setColor(Color.black);
        }
        frame.setVisible(visible);
    }

    /**
     * Draw a given shape onto the canvas.
     * @param  referenceObject  an object to define identity for this shape
     * @param  color            the color of the shape
     * @param  shape            the shape object to be drawn on the canvas
     */
     // Note: this is a slightly backwards way of maintaining the shape
     // objects. It is carefully designed to keep the visible shape interfaces
     // in this project clean and simple for educational purposes.
    public void draw(Object referenceObject, String color, Shape shape)
    {
        objects.add(referenceObject);      // add at the end
        shapes.put(referenceObject, new ShapeDescription(shape, color));
        redraw();
    }


    /**
     * Desenhar a imagem
     */
    public void drawImage(Object obj, int x, int y)
    {
        objetos.remove(obj);
        objetos.add(obj);

        int[] coord = new int[2];
        coord[0] = x*20;
        coord[1] = y*20;
        coordenadasObjetos.put( obj, coord );
        redraw();
    }



    /**
     * Erase a given shape's from the screen.
     * @param  referenceObject  the shape object to be erased
     */
    public void erase(Object referenceObject)
    {
        objects.remove(referenceObject);   // just in case it was already there
        shapes.remove(referenceObject);
        redraw();
    }

    /**
     * Set the foreground colour of the Canvas.
     * @param  newColour   the new colour for the foreground of the Canvas
     */
    public void setForegroundColor(String colorString)
    {
        if(colorString.equals("red"))
            graphic.setColor(Color.red);
        else if(colorString.equals("black"))
            graphic.setColor(Color.black);
        else if(colorString.equals("blue"))
            graphic.setColor(Color.blue);
        else if(colorString.equals("yellow"))
            graphic.setColor(Color.yellow);
        else if(colorString.equals("green"))
            graphic.setColor(Color.green);
        else if(colorString.equals("magenta"))
            graphic.setColor(Color.magenta);
        else if(colorString.equals("white"))
            graphic.setColor(Color.white);
        else
            graphic.setColor(Color.black);
    }

    /**
     * Wait for a specified number of milliseconds before finishing.
     * This provides an easy way to specify a small delay which can be
     * used when producing animations.
     * @param  milliseconds  the number
     */
    public void wait(int milliseconds)
    {
        try
        {
            Thread.sleep(milliseconds);
        }
        catch (Exception e)
        {
            // ignoring exception at the moment
        }
    }

    /**
     * Redraw ell shapes currently on the Canvas.
     */
    private void redraw()
    {
        int[] coord = null;
        erase();
        for(Iterator i=objects.iterator(); i.hasNext(); ) {
            ((ShapeDescription)shapes.get(i.next())).draw(graphic);
        }

        for(int i = 0; i<objetos.size(); i++) {
            BufferedImage imagen = this.getImage( ((Yoshi)objetos.get(i)).getColor() );
            if(imagen!=null){
                coord = (int[])coordenadasObjetos.get(objetos.get(i));
                graphic.drawRenderedImage(imagen,transformer.getTranslateInstance(coord[0],coord[1]));
            }

        }

        canvas.repaint();
    }

    /**
     * Erase the whole canvas. (Does not repaint.)
     */
    private void erase()
    {
        Color original = graphic.getColor();
        graphic.setColor(backgroundColour);
        Dimension size = canvas.getSize();
        graphic.fill(new Rectangle(0, 0, size.width, size.height));
        graphic.setColor(original);
    }


    /************************************************************************
     * Inner class CanvasPane - the actual canvas component contained in the
     * Canvas frame. This is essentially a JPanel with added capability to
     * refresh the image drawn on it.
     */
    private class CanvasPane extends JPanel
    {
        public void paint(Graphics g)
        {
            g.drawImage(canvasImage, 0, 0, null);
        }
    }



    /************************************************************************
     * Inner class CanvasPane - the actual canvas component contained in the
     * Canvas frame. This is essentially a JPanel with added capability to
     * refresh the image drawn on it.
     */
    private class ShapeDescription
    {
        private Shape shape;
        private String colorString;

        public ShapeDescription(Shape shape, String color)
        {
            this.shape = shape;
            colorString = color;
        }

        public void draw(Graphics2D graphic)
        {
            setForegroundColor(colorString);
            graphic.fill(shape);
        }
    }


    public BufferedImage getImage(String ycolor){
        File imageFile;
        BufferedImage bufferedImage = null;
        String fileName = "img/main.jpg";

        if(ycolor.compareTo("amarelo")==0){
            fileName = "img/yamarelo.png";
        } else if(ycolor.compareTo("vermelho")==0){
            fileName = "img/yvermelho.png";
        } else if(ycolor.compareTo("azul")==0){
            fileName = "img/yazul.png";
        } else if(ycolor.compareTo("verde")==0){
            fileName = "img/yverde.png";
        }

        try
        {
            imageFile = new File(fileName);
            // Read the file...
            bufferedImage = imageIO.read(imageFile);
        }
        catch(Exception e)
        {
            // Something went wrong!
            bufferedImage=null;
        }
        return bufferedImage;
    }

}
