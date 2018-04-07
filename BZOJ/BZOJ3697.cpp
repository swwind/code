//bzoj 3697 采药人的路径
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define M(a) memset(a,0,sizeof a)
#define fo(i,j,k) for(i=j;i<=k;i++)
using namespace std;
const int mxn=200005;
bool vis[mxn];
int n,m,mn,cnt,tot,root,mxdep;
ll h[mxn][2],g[mxn][2],ans;
struct edge {int to,w,next;} f[mxn<<1];
int head[mxn],size[mxn],dis[mxn],mx[mxn],dep[mxn],t[mxn];
inline void add(int u,int v,int w) {
  f[++cnt].to=v,f[cnt].w=w,f[cnt].next=head[u],head[u]=cnt;
}
inline void dfssize(int u,int fa) {
  size[u]=1,mx[u]=0;
  for(int i=head[u];i;i=f[i].next) {
    int v=f[i].to;
    if(vis[v] || v==fa) continue;
    dfssize(v,u);
    size[u]+=size[v];
    mx[u]=max(mx[u],size[v]);
  }
}
inline void dfsroot(int r,int u,int fa) {
  mx[u]=max(mx[u],size[r]-size[u]);
  if(mx[u]<mn) mn=mx[u],root=u;
  for(int i=head[u];i;i=f[i].next) {
    int v=f[i].to;
    if(vis[v] || v==fa) continue;
    dfsroot(r,v,u);
  }
}
inline void dfsdis(int u,int fa) {
  mxdep=max(mxdep,dep[u]);
  if(t[dis[u]]) h[dis[u]][1]++;
  else h[dis[u]][0]++;
  t[dis[u]]++;
  for(int i=head[u];i;i=f[i].next) {
    int v=f[i].to;
    if(vis[v] || v==fa) continue;
    dis[v]=dis[u]+f[i].w,dep[v]=dep[u]+1;
    dfsdis(v,u);
  }
  t[dis[u]]--;
}
inline void calc(int u) {
  tot=0,mxdep=0;g[n][0]=1;  //当前节点u
  for(int i=head[u];i;i=f[i].next) {
    mxdep=0;
    int v=f[i].to;
    if(vis[v]) continue;
    dep[v]=1,dis[v]=n+f[i].w;
    dfsdis(v,u),tot=max(tot,mxdep);
    ans+=(g[n][0]-1)*h[n][0];  //不含u 
    for(int j=-mxdep;j<=mxdep;j++)
      ans+=g[n-j][1]*h[n+j][0]+g[n-j][0]*h[n+j][1]+g[n-j][1]*h[n+j][1];
    for(int j=n-mxdep;j<=n+mxdep;j++) {
      g[j][0]+=h[j][0];
      g[j][1]+=h[j][1];
      h[j][0]=h[j][1]=0;
    }
  }
  for(int i=n-tot;i<=n+tot;i++)
    g[i][0]=g[i][1]=0;
}
inline void dfs(int u) {
  mn=n;
  dfssize(u,0);
  dfsroot(u,u,0);
  calc(root);
  vis[root]=1;
  for(int i=head[root];i;i=f[i].next) {
    int v=f[i].to;
    if(vis[v]) continue;
    dfs(v);
  }
}
int main() {
  int i,j,u,v,w;
  scanf("%d",&n);
  fo(i,2,n) {
    scanf("%d%d%d",&u,&v,&w);
    if(!w) w=-1;
    add(u,v,w),add(v,u,w);
  }
  dfs(1);
  printf("%lld\n",ans);
  return 0;
}  