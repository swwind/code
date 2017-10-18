import java.util.*;
import java.math.*;

public class Main {
	static int n, d[] = new int[10002];
	static BigInteger p[] = new BigInteger[1002];
	static BigInteger ans;
	
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		int sum = 0, flag = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			d[i] = scan.nextInt();
			if(d[i] == 0 || d[i] > n - 1) flag = 1;
			if(d[i] == -1) continue;
			sum += d[i]-1;
			cnt++;
		}
		scan.close();
		if(n==1) {
			if(d[0]==0 || d[0]==-1) System.out.println(1);
			else System.out.println(0);
			return;
		}
		if(n==2) {
			if((d[0]==-1 || d[0]==1) && (d[1]==-1 || d[1]==-1)) System.out.println(1);
			else System.out.println(0);
			return;
		}
		if(flag==1) System.out.println(0);
		p[0]=BigInteger.ONE;
		for(int i=1; i<=n; i++) p[i]=p[i-1].multiply(BigInteger.valueOf(i));
		ans=p[n-2].divide(p[n-2-sum]);
		for(int i=0; i<n; i++) {
			if(d[i]==-1) continue;
			ans=ans.divide(p[d[i]-1]);
		}
		for(int i=0; i<n-2-sum; i++) ans=ans.multiply(BigInteger.valueOf(n-cnt)); 
		System.out.println(ans);
	}
}
