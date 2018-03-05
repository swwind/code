#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 200003
#define ULL unsigned long long 
using namespace std;
const ULL mx=0-1;
int opt[N],n,m,k,point[N],nxt[N],v[N],belong[N],son[N];
int fa[N],size[N],pos[N],tot,deep[N],q[N],sz;
ULL val[N],mi[N];
struct data{
    ULL l0,l1,r0,r1; 
}tr[N*4],ans[N],ans1[N];
void add(int x,int y)
{
    tot++;  nxt[tot]=point[x]; point[x]=tot; v[tot]=y;
    tot++;  nxt[tot]=point[y]; point[y]=tot; v[tot]=x;
}
void dfs(int x,int f)
{
    size[x]=1; deep[x]=deep[f]+1;
    for (int i=point[x];i;i=nxt[i]){
        if (v[i]==f) continue;
        fa[v[i]]=x;
        dfs(v[i],x);
        size[x]+=size[v[i]];
        if (size[v[i]]>size[son[x]]) son[x]=v[i];
    }
}
void dfs1(int x,int chain)
{
    belong[x]=chain; pos[x]=++sz; q[sz]=x;
    if (!son[x]) return;
    dfs1(son[x],chain);
    for (int i=point[x];i;i=nxt[i])
     if (v[i]!=son[x]&&v[i]!=fa[x])
      dfs1(v[i],v[i]);
}
ULL calc(ULL num,int x)
{
    if (opt[x]==1) return num&val[x];
    if (opt[x]==2) return num|val[x];
    if (opt[x]==3) return num^val[x];
}
data update(data l,data r)
{
    data now; now.l0=now.l1=now.r1=now.r0=0;
    now.l0=(l.l0&r.l1)|((~l.l0)&r.l0);
    now.l1=(l.l1&r.l1)|((~l.l1)&r.l0);
    now.r0=(r.r0&l.r1)|((~r.r0)&l.r0);
    now.r1=(r.r1&l.r1)|((~r.r1)&l.r0);
    cout << now.l0 << " " << now.l1 << " " << now.r0 << " " << now.r1 << endl;
    return now;
}
void build(int now,int l,int r)
{
    if (l==r) {
        int t=q[l];
        tr[now].l0=calc(0,t);
        tr[now].l1=calc(mx,t);
        tr[now].r0=calc(0,t);
        tr[now].r1=calc(mx,t);
        return;
    }
    int mid=(l+r)/2;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    tr[now]=update(tr[now<<1],tr[now<<1|1]);
}
void pointchange(int now,int l,int r,int x)
{
    if (l==r) {
        int t=q[l];
        tr[now].l0=calc(0,t);
        tr[now].l1=calc(mx,t);
        tr[now].r0=calc(0,t);
        tr[now].r1=calc(mx,t);
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid) pointchange(now<<1,l,mid,x);
    else pointchange(now<<1|1,mid+1,r,x);
    tr[now]=update(tr[now<<1],tr[now<<1|1]);
}
data query(int now,int l,int r,int ll,int rr)
{
    if (ll<=l&&r<=rr) return tr[now];
    int mid=(l+r)/2;
    data ans; bool pd=false;
    if (ll<=mid) ans=query(now<<1,l,mid,ll,rr),pd=true;
    if (rr>mid) {
        if (pd) ans=update(ans,query(now<<1|1,mid+1,r,ll,rr));
        else ans=query(now<<1|1,mid+1,r,ll,rr);
    }
    return ans;
}
data solve(int x,int y)
{
    int cnt=0,cnt1=0;
    while (belong[x]!=belong[y]) {
        if (deep[belong[x]]>deep[belong[y]]){
            ans[++cnt]=query(1,1,n,pos[belong[x]],pos[x]);
            x=fa[belong[x]];
        }
        else {
            ans1[++cnt1]=query(1,1,n,pos[belong[y]],pos[y]);
            y=fa[belong[y]];
        }
    }
    if (deep[x]<deep[y]) ans1[++cnt1]=query(1,1,n,pos[x],pos[y]);
    else ans[++cnt]=query(1,1,n,pos[y],pos[x]);
    for (int i=1;i<=cnt;i++) swap(ans[i].l0,ans[i].r0),swap(ans[i].l1,ans[i].r1);
    data sum; 
    if (cnt) {
       sum=ans[1];
       for (int i=2;i<=cnt;i++) sum=update(sum,ans[i]);
       if (cnt1) sum=update(sum,ans1[cnt1]);
    }
    else sum=ans1[cnt1];
    for (int i=cnt1-1;i>=1;i--) sum=update(sum,ans1[i]);
    return sum; 
}
int main()
{
    scanf("%d%d%d",&n,&m,&k); mi[0]=1;
    for (int i=1;i<=k-1;i++) mi[i]=mi[i-1]*2;
    for (int i=1;i<=n;i++) scanf("%d%llu",&opt[i],&val[i]);
    for (int i=1;i<n;i++) {
        int x,y; scanf("%d%d",&x,&y);
        add(x,y);
    }
    dfs(1,0); dfs1(1,1);
    build(1,1,n);
    for (int i=1;i<=m;i++) {
        int op,x,y; ULL z; scanf("%d%d%d%llu",&op,&x,&y,&z);
        if (op==2) {
            opt[x]=y; val[x]=z;
            pointchange(1,1,n,pos[x]);
        }
        else {
            data t=solve(x,y); ULL ans=0;
            printf("%llu %llu\n", t.l0, t.l1);
            for (int i=63;i>=0;i--) {
                ULL t0=(t.l0>>i)&1;
                ULL t1=(t.l1>>i)&1;
                if (t0>=t1||mi[i]>z) ans|=(t0?mi[i]:0);
                else ans|=(t1?mi[i]:0),z-=mi[i];
            }
            printf("%llu\n",ans);
        }
    }
} 