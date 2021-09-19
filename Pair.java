import java.util.Objects;

public class Pair {
	private int a;
	private int b;
	
	public Pair(int a,int b) {
		this.a=a;
		this.b=b;
	}
	public Pair() {
		
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(a, b);
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pair other = (Pair) obj;
		return a == other.a && b == other.b;
	}
	

}
