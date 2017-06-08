//WTF????
#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void writeln(ll x){
	if(x<0)putchar('-'),x=-x;
	write(x);puts("");
}
ll n,k,S,nb,w[50],flag,v[50],qwq[1000000];
map<ll, map<ll, ll> > mp1,mp2;
map<ll, ll> as;
ll get(ll x){
	if(x>20)return -1;
	ll sum=1;
	for(ll i = 2; i <= x; i++)
		sum*=i;
	return sum;
}
ll Pow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1)ans*=a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
ll a[50];
void add(){
	a[1]++;
	int k = 1;
	while(a[k]==3)a[++k]++;
	if(k>nb)flag=1;
}
void addAns(){
	ll sum1=0,sum2=0,fc=0,die1=0,die2=0;
	for(int i = 1; i <= nb; i++){
		if(a[i]==1){
			if(!die1)sum1+=v[i];if(!die2)sum2+=v[i+nb];
		}
		if(a[i]==2){
			fc++;
			if(w[i]==-1)die1=1;
			else sum1+=w[i];
			if(w[i+nb]==-1)die2=1;
			else sum2+=w[i+nb];
		}
	}
	if(!die1&&!as[sum1])qwq[++qwq[0]]=sum1,as[sum1]++;
	// for(int i = 1; i <= nb; i++)printf("%d ", a[i]);puts("");
	// printf("%lld %lld fc=%lld\n", sum1, sum2, fc);
	if(!die1)mp1[sum1][fc]++;
	if(!die2)mp2[sum2][fc]++;
}
int main(){
	n=read(); k=read(); S=read();
	for(int i = 1; i <= n; i++)
		w[i]=get(v[i]=read());
	nb=n>>1;
	while(!flag){
		addAns();
		add();
	}
	ll ans = 0;
	for(int i = 1; i <= qwq[0]; i++)for(int j = 0; j <= k; j++)for(int l=0;l<=k-j;l++)
		ans += min(mp1[qwq[i]][j], mp2[S-qwq[i]][l]);
	if(n&1){
		int s = S-v[n];
		for(int i = 1; i <= qwq[0]; i++)for(int j = 0; j <= k; j++)for(int l=0;l<=k-j;l++)
			ans += min(mp1[qwq[i]][j], mp2[s-qwq[i]][l]);
		s = S-w[n];k--;
		for(int i = 1; i <= qwq[0]; i++)for(int j = 0; j <= k; j++)for(int l=0;l<=k-j;l++)
			ans += min(mp1[qwq[i]][j], mp2[s-qwq[i]][l]);
	}
	writeln(ans);
}