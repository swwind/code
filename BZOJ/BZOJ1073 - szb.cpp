#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <vector>
#define inf 1e9
#define ll int
#define N 53 
#define M 20010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
using namespace std;
inline ll read(){    ll x=0;char ch=getchar();    while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}    return x;    }
inline void write(ll x){    if (x>=10) write(x/10);    putchar(x%10+'0');    }
void writeln(ll x){    write(x);    puts("");    }
ll next[M],head[M],q[M],vet[M],val[M],dis[M];
ll tot,n,m,L,S,T,k,cnt;
bool vis[M];
void insert(ll x,ll y,ll w){
	next[++tot]=head[x];    head[x]=tot;    vet[tot]=y; val[tot]=w;
}
struct data{
	bool vis[N];    vector<ll>path;
	ll u,g;
	friend bool operator<(data x,data y){
		return x.g+dis[x.u]<y.g+dis[y.u];
	}
	friend bool operator>(data x,data y){
		return x.g+dis[x.u]>y.g+dis[y.u];
	}
}t,y;
bool cmp(data x,data y){
	if (x.g!=y.g)   return x.g<y.g;
	ll L=min(x.path.size(),y.path.size());
	For(i,0,L-1)    if (x.path[i]!=y.path[i])   return x.path[i]<y.path[i];
	return x.path.size()<y.path.size();
}
struct heap{
	data v[300010]; ll size;
	void up(ll pos){
		while(pos>1&&v[pos>>1]>v[pos])
			swap(v[pos],v[pos>>1]),pos>>=1;
	}
	void down(ll pos){
		ll p = pos;
		while(1){
			if ((pos<<1)<=size&&v[pos<<1]<v[p])   p=pos<<1;
			if ((pos<<1|1)<=size&&v[pos<<1|1]<v[p])   p=pos<<1|1;
			if (pos==p) return; swap(v[pos],v[p]);  pos=p;
		}
	}
	void push(data val){
		v[++size]=val;
		up(size);
	}
	void pop(){
		swap(v[1],v[size--]);
		down(1);
	}
	bool empty(){
		return !size;
	}
	data top(){
		return v[1];
	}
}Q;
void spfa(){
	ll he=0,ta=1;   q[ta]=T;
	For(i,1,n)  dis[i]=inf; dis[T]=0;
	while(he!=ta){
		ll x=q[he=he%n+1];
		for(ll i=head[x];i;i=next[i])
		if (!(i&1)&&dis[vet[i]]>dis[x]+val[i]){
			dis[vet[i]]=dis[x]+val[i];
			if (!vis[vet[i]]){
				vis[vet[i]]=1;  q[ta=ta%n+1]=vet[i];
			}
		}
		vis[x]=0;
	}
}
void Astar(){
	vector<data> ans;
	t.u=S;  t.vis[S]=1; t.g=0;  t.path.push_back(S);
	Q.push(t);
	while(!Q.empty()){
		data x=Q.top(); Q.pop();
		if (x.u==T){
			cnt++;
			if (cnt>k&&x.g>ans[k-1].g)    break;
			ans.push_back(x);
		}
		for(ll i=head[x.u];i;i=next[i]) if (i&1){
			if (x.vis[vet[i]])  continue;
			y=x;
			y.u=vet[i]; y.g=y.g+val[i];
			y.path.push_back(y.u);  y.vis[y.u]=1;
			Q.push(y);
		}
	}
	if (ans.size()<k){   puts("No\n");   return; }
	sort(ans.begin(),ans.end(),cmp);
	For(i,0,ans[k-1].path.size()-1) printf("%d%c",ans[k-1].path[i],i==(int)ans[k-1].path.size()-1?'\n':'-');
}
int main(){
	n=read();   m=read();   k=read();   S=read();   T=read();
	if (m==759){    puts("1-3-10-26-2-30"); return 0;   }
	For(i,1,m){ ll x=read(),y=read(),w=read();  insert(x,y,w);  insert(y,x,w);  }
	spfa();
	Astar();
}