import java.io.*;
import java.util.*;

public class Main {
	public PriorityQueue <Integer> que = new PriorityQueue <> ();
	public int op[] = new int[1000020];
	public int vl[] = new int[1000020];
	public int cnt = 0;
	public Scanner scan;
	public Main (Scanner scan) {
		this.scan = scan;
	}
	public void work() {
		int n = scan.nextInt();
		// System.out.println("readed " + n);
		for (int i = 1; i <= n; i++) {
			String str = scan.next();
			// System.out.println("Iteration " + i + " -> " + str);
			if (str.equals("removeMin")) {
				if (que.size() == 0) {
					op[++cnt] = 1;
					vl[cnt] = 233;
				} else {
					que.poll();
				}
				op[++cnt] = 3;
			} else if (str.equals("getMin")) {
				int x = scan.nextInt();
				while (que.size() > 0 && que.peek() < x) {
					que.poll();
					op[++cnt] = 3;
				}
				if (que.size() == 0 || que.peek() != x) {
					que.add(x);
					op[++cnt] = 1;
					vl[cnt] = x;
				}
				op[++cnt] = 2;
				vl[cnt] = x;
			} else if (str.equals("insert")) {
				int x = scan.nextInt();
				que.add(x);
				op[++cnt] = 1;
				vl[cnt] = x;
			}
			// System.out.println("now size: " + que.size());
		}
		scan.close();
		System.out.println(cnt);
		for (int i = 1; i <= cnt; i++) {
			if (op[i] == 1)
				System.out.println("insert " + vl[i]);
			else if (op[i] == 2)
				System.out.println("getMin " + vl[i]);
			else
				System.out.println("removeMin");
		}
	}
	public static void main(String[] args) {
		Main main = new Main(new Scanner(System.in));
		main.work();
	}
}
