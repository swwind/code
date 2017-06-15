#include <bits/stdc++.h>
#define N 1007
#define id(i, j) (i-1)*m+j
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int mx[N][N], mn[N][N], a[N][N];
int t1[N], t2[N], pos[N], val[N];
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = read();
	for(int i = 1; i <= n; i++){
		int l = 1, r = 1;
		for(int j = 1; j <= m; j++){
			while(l < r && val[r-1] <= a[i][j]) r--;
			val[r] = a[i][j]; pos[r] = j; r++;
			if(pos[l] == j-k) l++;
			if(j >= k) mx[i][j] = val[l];
		}
	}
	for(int i = 1; i <= n; i++){
		int l = 1, r = 1;
		for(int j = 1; j <= m; j++){
			while(l < r && val[r-1] >= a[i][j]) r--;
			val[r] = a[i][j]; pos[r] = j; r++;
			if(pos[l] == j-k) l++;
			if(j >= k) mn[i][j] = val[l];
		}
	}
	int ans = 1<<30;
	for(int j = k; j <= m; j++){
		int l = 1, r = 1;
		for(int i = 1; i <= n; i++){
			while(l < r && val[r-1] >= mn[i][j]) r--;
			val[r] = mn[i][j]; pos[r] = i; r++;
			if(pos[l] == i-k) l++;
			if(i >= k) t1[i] = val[l];
		}l = r = 1;
		for(int i = 1; i <= n; i++){
			while(l < r && val[r-1] <= mx[i][j]) r--;
			val[r] = mx[i][j]; pos[r] = i; r++;
			if(pos[l] == i-k) l++;
			if(i >= k) t2[i] = val[l];
		}
		for(int i = k; i <= n; i++)
			ans = min(ans, t2[i]-t1[i]);
	}
	printf("%d\n", ans);
}
/*
5 5 2
5 5 4 9 2
5 4 1 3 9
9 4 6 2 8
8 7 6 5 1
9 5 6 5 4

*/