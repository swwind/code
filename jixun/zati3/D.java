import java.util.Scanner;
public class D {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long x = scan.nextLong() * 2;
		long y = scan.nextLong();
		scan.close();
		long ans = 0;
		if (y > x) ans = x / 2 + (y - x) / 4;
		else ans = Math.min(x / 2, y / 2);
		System.out.println(ans);
		return;
	}
}