#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1005
#define mod 1000000007
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
    char ch=getchar(); ll x=0,f=1;
    while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return x*f;
}
ll n,m,k,f[N][N],a[N][N],num[20];
ll dfs(ll x,ll y){
    if (y>m) { ++x,y=1;    }
    if (x>n) return 1;
    ll now=f[x-1][y]|f[x][y-1],cnt=0,flag=-1,ans=0;
    for (ll i=now;i;i-=i&-i) ++cnt;
    if (n+m-x-y+1>k-cnt) return 0;
    for (ll i=(~now)&((1<<k)-1);i;i-=i&-i){
        ll t=log((i&-i)+0.5)/log(2)+1;
        if (!a[x][y]||a[x][y]==t){
            ++num[t]; f[x][y]=now|(i&-i);
            if (num[t]==1){
                if (flag==-1) flag=dfs(x,y+1);
                    ans+=flag;
            }else ans+=dfs(x,y+1);
            ans%=mod; --num[t];
        }
    }
    return ans;
}
int main(){
    n=read(); m=read(); k=read();
    rep(i,1,n) rep(j,1,m) ++num[a[i][j]=read()];
    printf("%lld",dfs(1,1));
}