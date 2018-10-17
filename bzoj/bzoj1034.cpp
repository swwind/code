#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
int a[100020], b[100020], n;
int get(int *a, int *b){
	int l1 = 1, r1 = n, l2 = 1, r2 = n, ans = 0;
	while(l1<=r1&&l2<=r2)
		if(a[l1]>b[l2])ans+=2,l1++,l2++;
		else if(a[r1]>b[r2])ans+=2,r1--,r2--;
		else ans+=(a[l1++]==b[r2--]);
	return ans;
}
int main(){
	n = read();
	for(int i = 1; i <= n; i++)
		a[i]=read();
	for(int i = 1; i <= n; i++)
		b[i]=read();
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	printf("%d %d", get(a, b), n*2-get(b, a));
}
