import java.util.Scanner;
public class B {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int z = 1 << 30, sum = 0;
		for (int i = 1; i <= n; i++) {
			int x = scan.nextInt();
			sum += x;
			if (x % 10 > 0)
				z = Math.min(z, x);
		}
		if (sum % 10 == 0)
			System.out.println(z == 1 << 30 ? 0 : sum - z);
		else
			System.out.println(sum);
		return;
	}
}