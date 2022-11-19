package dasdfsadsadsad;

public class Position implements Comparable<Position>{
	int x;
	int y;
	Position(int x,int y){
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(Position i) {
		return (int)(Math.sqrt(x*x+y*y)-Math.sqrt(i.x*i.x+i.y*i.y));
	}

}
