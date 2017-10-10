import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for (int i = 1; i <= n; i++) {
			String str = scan.next();
			int x = scan.nextInt();
			int y = scan.nextInt();
			if (x >= 2400 && y > x) {
				System.out.println("YES");
				scan.close();
				return;
			}
		}
		System.out.println("NO");
		scan.close();
	}
}
