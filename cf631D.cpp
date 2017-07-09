#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	int l;
	char c;
	void read(){scanf("%d-%c", &l, &c);}
	bool operator == (const node &b) const {
		return l == b.l && c == b.c;
	}
	bool operator != (const node &b) const {
		return l != b.l || c != b.c;
	}
}a[N], b[N];
int nxt[N];
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++){
		a[i].read();
		if(a[i].c == a[i-1].c){
			n--;i--;a[i-1].l += a[i].l;
		}
	}
	for(int i = 0; i < m; i++){
		b[i].read();
		if(b[i].c == b[i-1].c){
			m--;i--;b[i-1].l += b[i].l;
		}
	}
	m -= 2;
	int ans = 0;
	if(m == -1){
		for(int i = 1; i <= n; i++)
			if(a[i].c == b[0].c && a[i].l >= b[0].l)
				ans+=a[i].l-b[0].l+1;
	}
	else if(m == 0){
		for(int i = 2; i <= n; i++)
			if(a[i-1].c == b[0].c && a[i-1].l >= b[0].l && a[i].c == b[1].c && a[i].l >= b[i].l)
				ans++;
	}
	else{
		for(int i = 2, j = 0; i <= m; i++){
			while(j && b[j+1] != b[i]) j = nxt[j];
			if(b[j+1] == b[i]) j++; nxt[i] = j;
		}
		for(int i = 1, j = 0; i <= n; i++){
			while(j && a[i] != b[j+1]) j = nxt[j];
			if(a[i] == b[j+1]) j++;
			if(j == m){
				if(a[i+1].c == b[m+1].c && a[i+1].l >= b[m+1].l && a[i-m].c == b[0].c && a[i-m].l >= b[0].l){
					ans++;
				j = nxt[j];
				}
			}
		}
	}
	printf("%d\n", ans);
}