import java.math.*;
public class Main {
	public static void main(String[] args) {
		BigDecimal a = new BigDecimal(".1");
		BigDecimal b = new BigDecimal(".2");
		System.out.println(a.add(b).toString());
	}
}