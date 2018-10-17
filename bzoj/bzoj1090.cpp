#include <bits/stdc++.h>
#define N 120
#define ll long long
#define Fallen int
#define Original int
#define Author int
#define The bool
#define Radio int
#define _ int
#define Edit l,_ r,_ cl,_ cr
#define mix l,_ r
#define Sky int
#define High main
#define Back inline
#define On int
using namespace std;
char s[N];
_ f[N][N], mark[N][N];
Back On Track(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
The Ocean(Radio Edit){
	if((r-l+1)%(cr-cl+1))return 0;
	for(_ i = l; i <= r; i++)
		if(s[i] != s[(i-l)%(cr-cl+1)+cl])
			return 0;
	return 1;
}
Fallen Angels(Original Mix){
	Author ZARB = 0;
	for(;Mix;Mix/=10)ZARB++;
	return ZARB;
}
_ Xenogenesis(Original mix){
	if(l == r) return 1;
	if(mark[l][r]) return f[l][r]; 
	mark[l][r] = 1;
	_ t = r-l+1;
	for(_ i = l; i < r; i++){
		t = min(t, Xenogenesis(l, i)+Xenogenesis(i+1, r));
		if(Ocean(i+1, r, l, i))
			t = min(t, Xenogenesis(l, i)+2+Angels((r-i)/(i-l+1)+1)); 
	}
	return f[l][r] = t;
}
Sky High(){
	scanf("%s", s);
	printf("%d\n", Xenogenesis(0, strlen(s)-1));
}