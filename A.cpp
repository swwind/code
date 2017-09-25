#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[125][2025], last[125][2025], vis[125][2025];
int sta[125], top;
int n = read(), ans, mxt, num;
struct node{
	int thisisalongvarname, thisisanotherlongvarname, thisisthenonono, num;
	friend bool operator < (const node &aa, const node &bb) {
		return aa.thisisanotherlongvarname < bb.thisisanotherlongvarname;
	}
}miku[125];
int main(){
	for (int i = 1; i <= n; i++){
		miku[i].thisisalongvarname = read(); miku[i].thisisanotherlongvarname = read(); miku[i].thisisthenonono = read();
		miku[i].num = i;
		mxt = max(mxt,miku[i].thisisanotherlongvarname);
	}
	sort(miku+1, miku+n+1);
	for (int i = 1; i <= n; i++){
		for (int j = miku[i].thisisalongvarname; j < miku[i].thisisanotherlongvarname; j++){
			if(f[i][j] <= f[i-1][j-miku[i].thisisalongvarname]+miku[i].thisisthenonono){
				f[i][j] = f[i-1][j-miku[i].thisisalongvarname]+miku[i].thisisthenonono;
				last[i][j] = j-miku[i].thisisalongvarname;
				vis[i][j] = 1;
			}
		}
		for (int j = 0; j < mxt; j++)
			if(f[i][j] <= f[i-1][j]) {
				f[i][j] = f[i-1][j];
				last[i][j] = j;
				vis[i][j] = 0;
			}
	}
	for (int i = 0; i < mxt; i++)
		if(ans < f[n][i])
			ans = f[n][num = i];
	printf("%d\n", ans);
	for (int i = n; i; i--){
		if (vis[i][num])
			sta[++top] = miku[i].num;
		num = last[i][num];}
	printf("%d\n", top);
	while (top) printf("%d ",sta[top--]);
	return 0;
}
