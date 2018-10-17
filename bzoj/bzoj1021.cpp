#include <bits/stdc++.h>
#define N 105
#define ll long long
#define inf 707406378
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int f[2][1020][1020]; // A -> i, B -> j, C -> (sum-i-j)
int mon[] = {100, 50, 20, 10, 5, 1};
int a[6], b[6], c[6], A, B, C;
void mins(int &a, int b){
	if(b < a) a = b;
}
int main(){
	int x1 = read(), x2 = read(), x3 = read();
	for(int i = 0; i < 6; i++) A += mon[i]*(a[i] = read());
	for(int i = 0; i < 6; i++) B += mon[i]*(b[i] = read());
	for(int i = 0; i < 6; i++) C += mon[i]*(c[i] = read());
	int sum = A+B+C; memset(f, 127/3, sizeof f); f[1][A][B] = 0;
	for(int i = 0; i < 6; i++){
		memset(f[i&1], 127/3, sizeof f[i&1]);
		for(int x = 0; x <= sum; x++) for(int y = 0; y <= sum-x; y++){
			if(f[~i&1][x][y] == inf) continue;
			int z = sum-x-y;
			for(int j = 0; j <= a[i]; j++) for(int k = 0; k <= a[i]-j; k++)
				if((j+k)*mon[i] <= x) mins(f[i&1][x-(j+k)*mon[i]][y+j*mon[i]], f[~i&1][x][y]+j+k);
			for(int j = 0; j <= b[i]; j++) for(int k = 0; k <= b[i]-j; k++)
				if((j+k)*mon[i] <= y) mins(f[i&1][x+j*mon[i]][y-(j+k)*mon[i]], f[~i&1][x][y]+j+k);
			for(int j = 0; j <= c[i]; j++) for(int k = 0; k <= c[i]-j; k++)
				if((j+k)*mon[i] <= z) mins(f[i&1][x+j*mon[i]][y+k*mon[i]], f[~i&1][x][y]+j+k);
			int aa = min(a[i], x/mon[i]), bb = min(b[i], y/mon[i]), cc = min(c[i], z/mon[i]);
			for(int j = 0; j <= aa; j++) for(int k = 0; k <= bb; k++)
				mins(f[i&1][x-j*mon[i]][y-k*mon[i]], f[~i&1][x][y]+j+k);
			for(int j = 0; j <= aa; j++) for(int k = 0; k <= cc; k++)
				mins(f[i&1][x-j*mon[i]][y+(j+k)*mon[i]], f[~i&1][x][y]+j+k);
			for(int j = 0; j <= bb; j++) for(int k = 0; k <= cc; k++)
				mins(f[i&1][x+(j+k)*mon[i]][y-j*mon[i]], f[~i&1][x][y]+j+k);
		}
	}
	A = A-x1+x3;
	B = B-x2+x1;
	C = C-x3+x2;
	if(A < 0 || B < 0 || C < 0 || f[1][A][B] == inf) puts("impossible");
	else printf("%d\n", f[1][A][B]);
}