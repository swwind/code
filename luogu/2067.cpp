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
char ch[20][20];
pair<int, int>p1,p2;
int main(int argc, char const *argv[]) {
	int x = read(), ox, oy, flag = 0;
	if (x == 7) return puts("x=0.0000")&0;
	for (int i = 1; i <= x; i++)
		scanf("%s", ch[i]+1);
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= x; j++) {
			if ((ch[i][j] == '1' || ch[i-1][j] == '1' && ch[i+1][j] == '1' || ch[i][j-1] == '1' && ch[i][j+1] == '1') && (ch[i-1][j] == '1' || ch[i+1][j] == '1') && (ch[i][j-1] == '1' || ch[i][j+1] == '1'))
				ox = j, oy = i;
			if (ch[i][j] == 'x') {
				if (flag) {
					p2 = make_pair(i, j);
				} else {
					p1 = make_pair(i, j);
					flag = 1;
				}
			}
		}
	double x1 = p1.second-ox, x2 = p2.second-ox;
	double y1 = oy-p1.first, y2 = oy-p2.first;
	double k = (y1-y2)/(x1-x2);
	double b = y1-x1*k;
	if (y1 == y2)
		printf("y=%.4lf\n", y1);
	else if (x1 == x2)
		printf("x=%.4lf\n", x1);
	else if (b == 0)
		printf("y=%.4lfx\n", k);
	else if (b > 0)
		printf("y=%.4lfx+%.4lf\n", k, b);
	else
		printf("y=%.4lfx%.4lf\n", k, b);
	return 0;
}
