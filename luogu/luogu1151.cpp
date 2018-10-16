#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(int argc, char const *argv[]) {
	int s = read(), flag = 0;
	for (int i = 100; i <= 300; i++)
		if (i%s == 0) {
			if (i == 300) printf("%d\n", flag = 30000);
			else for (int j = 0; j < 10; j++)
				if ((i%100*10+j)%s == 0)
					for (int k = 0; k < 10; k++)
						if ((i%10*100+j*10+k)%s == 0)
							printf("%d\n", flag = i*100+j*10+k);
		}
	if (!flag) puts("No");
	return 0;
}