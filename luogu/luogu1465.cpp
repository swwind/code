#include <bits/stdc++.h>
int i, v, x, l, c, d, m, n;
int main(){
	scanf("%d",&n);
	for(int woc = 1, k = 1; woc <= n; k = ++woc)
		while(k)
			if(k >= 1000)
				k -= 1000,
				m++;
			else if(k >= 900)
				k -= 900,
				m++,
				c++;
			else if(k >= 500)
				k -= 500,
				d++;
			else if(k >= 400)
				k -= 400,
				d++,
				c++;
			else if(k >= 100)
				k -= 100,
				c++;
			else if(k >= 90)
				k -= 90,
				x++,
				c++;
			else if(k >= 50)
				k -= 50,
				l++;
			else if(k >= 40)
				k -= 40,
				l++,
				x++;
			else if(k >= 10)
				k -= 10,
				x++;
			else if(k >= 9)
				k -= 9,
				i++,
				x++;
			else if(k >= 5)
				k -= 5,
				v++;
			else if(k >= 4)
				k -= 4,
				i++,
				v++;
			else if(k >= 1)
				k--,
				i++;
	if(i) printf("I %d\n", i);
	if(v) printf("V %d\n", v);
	if(x) printf("X %d\n", x);
	if(l) printf("L %d\n", l);
	if(c) printf("C %d\n", c);
	if(d) printf("D %d\n", d);
	if(m) printf("M %d\n", m);
	return 0;
}
