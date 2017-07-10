#include <bits/stdc++.h>
#define N 30020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char ch[N], ans[N];
int check(int l, int r){
	while(l < r && ch[l] == ch[r])
		l++, r--;
	return ch[l] < ch[r];
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) scanf("%s", ch+i);
	int l = 1, r = n;
	for(int i = 1; i <= n; i++)
		ans[i] = check(l, r) ? ch[l++] : ch[r--];
	for(int i = 1; i <= n; i++){
		putchar(ans[i]);
		if(i%80 == 0) puts("");
	}
}
