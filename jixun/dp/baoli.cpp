#include <bits/stdc++.h>
#define N 1505
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
char ch[N][N];
int main(int argc, char const *argv[]) {
	int n = read(), q = read();
	for (int i = 1; i <= n; i++)
		scanf("%s", ch[i] + 1);
	while (q --) {
		int x = read(), y = read(), res = 0;
		for (int i = 1; i + x - 1 <= n; i++) {
			for (int j = 1; j + y - 1 <= n; j++) {
				int flag = 1;
				for (int k = 0; k < x && flag; k++)
					if (ch[i + k][j] == '0' || ch[i + k][j + y - 1] == '0')
						flag = 0;
				for (int k = 0; k < y && flag; k++)
					if (ch[i][j + k] == '0' || ch[i + x - 1][j + k] == '0')
						flag = 0;
				res += flag;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}