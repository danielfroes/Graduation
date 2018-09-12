//Daniel Fróes
//10255956
public class Person {
	private String name;
	private String date;
	private double height;
	private double weight;
	//atributos
	public Person(String name){
		this.name = name;
	}
	
	public Person(String name, String date, double height, double weight){
		this.name = name;
		this.date = date;
		this.height = height;
		this.weight = weight;
	}
	public String toString(){
		return ("Nome: "+ name + ", Data de nascimento: " + date + ", Altura: " + height + ", IMC: " + this.imc());
	}

	public double imc(){
		return weight/(height*height);
	}
	public String getName(){
		return name;
	}
	public void setName(String name){
		this.name  = name;
	}
	public String getDate(){
		return date;
	}
	public void setDate(String date){
		this.date  = date;
	}
	public double getHeight(){
		return height;
	}
	public void setHeight(double height){
		this.height  = height;
	}
	public double getWeight(){
		return weight;
	}
	public void setWeight(double weight){
		this.weight  = weight;
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person p1 = new Person("Rafael", "23/01/1991", 1.72, 106.0);
		Person p2 = new Person("Maria", "13/02/1981", 1.82, 65.0);
		Person p3 = new Person("Mairo", "20/11/1890", 1.98, 132.0);
		
		System.out.println(p1 == p2);
		System.out.println(p2 == p3);
		
		System.out.println(p1.imc());
		System.out.println(p2.imc());
		System.out.println(p3.imc());
		
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
		
	}

}
