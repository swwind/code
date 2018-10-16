#include<algorithm>
#include<iostream>
#define N 1500000
#include<cstdio>
using namespace std;
int re[N],c[N][2],mx[N],val[N],fa[N];
int s[N],top;

bool isroot(int now)
{
    return !fa[now]||(c[fa[now]][0]!=now&&c[fa[now]][1]!=now);
}
void down(int now)
{
    if(re[now])
    {
        re[now]^=1;
        re[c[now][0]]^=1;
        re[c[now][1]]^=1;
        swap(c[now][0],c[now][1]);
    }
}
void update(int now)
{
    mx[now]=now;
    if(val[ mx[c[now][0]] ]>val[mx[now]]) mx[now]=mx[c[now][0]];
    if(val[ mx[c[now][1]] ]>val[mx[now]]) mx[now]=mx[c[now][1]];
}
void rotate(int now)
{
    int F=fa[now],Y=fa[F];
    int r=c[F][0]==now,l=r^1;

    if(!isroot(F))
        if(c[Y][0]==F) c[Y][0]=now;
    else c[Y][1]=now;

    fa[now]=Y;fa[F]=now;
    c[F][l]=c[now][r];
    fa[c[now][r]]=F;
    c[now][r]=F;
    update(F); 
    update(now);
}
void splay(int now)
{
    s[top=1]=now;
    for(int i=now;!isroot(i);i=fa[i]) s[++top]=fa[i];
    while(top) down(s[top--]);
    while(!isroot(now))
    {
        int F=fa[now],Y=fa[F];
        if(!isroot(F))
        {
            if((c[Y][0]==F)^(c[F][0]==now)) rotate(now);
            else rotate(F);
        }
        rotate(now);
    }
}
void access(int now)
{
    int last=0;
    while(now)
        splay(now),c[now][1]=last,
        update(now),last=now,now=fa[now];
}

void makeroot(int x)
{
    access(x);splay(x);re[x]^=1;
}
void link(int x,int y)
{
    makeroot(x);fa[x]=y;
}
void cut(int x,int y)
{
    makeroot(x);access(y);splay(y);fa[x]=c[y][0]=0;
}
int query(int x,int y)
{
    makeroot(x);access(y);splay(y);return mx[y];
}

struct eage
{
    int u,v,l,id;
    bool po;
}e[N];
struct node
{
    int x,y,ans,id,fl; 
}q[N];
int n,m,Q;

bool comp1(eage aa,eage bb)
{
    return aa.u==bb.u?aa.v<bb.v:aa.u<bb.u;
}
bool comp2(eage aa,eage bb)
{
    return aa.l<bb.l;
}
bool comp3(eage aa,eage bb)
{
    return aa.id<bb.id;
}
int findit(int u,int v)
{
    int l=1,r=m;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(e[mid].u<u||(e[mid].u==u&&e[mid].v<v))l=mid+1;
        else if(e[mid].u==u&&e[mid].v==v)return mid;
        else r=mid-1;
    }
}
int f[N];
int get_f(int now)
{
    return now==f[now]?f[now]:f[now]=get_f(f[now]);
}
void KU()
{
    for(int i=1;i<=n;++i) f[i]=i;
    sort(e+1,e+m+1,comp3);
    int tot=0;
    for(int i=1;i<=m;++i)
    {
        if(e[i].po) continue; 
        int x=get_f(e[i].u),y=get_f(e[i].v);
        if(x==y) continue;
        tot++;
        f[x]=y;
        link(e[i].u,i+n);
        link(e[i].v,i+n);
        if(tot==n-1) return;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
        if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
    }
    //buid
    sort(e+1,e+m+1,comp2);
    for(int i=1;i<=m;++i)
    {
        e[i].id=i;
        val[n+i]=e[i].l;
        mx[n+i]=n+i;
    }
    //in
    sort(e+1,e+m+1,comp1);
    for(int i=1;i<=Q;++i)
    {
        scanf("%d%d%d",&q[i].fl,&q[i].x,&q[i].y);
        if(q[i].fl==2)
        {
            if(q[i].x>q[i].y) swap(q[i].x,q[i].y);
            int id=findit(q[i].x,q[i].y);
            q[i].id=e[id].id;
            e[id].po=1;
        }
    }

    KU();
    for(int i=Q;i;--i) 
    {
        if(q[i].fl==1) q[i].ans=val[query(q[i].x,q[i].y)];
        else//join
        {
            int bi=query(q[i].x,q[i].y);
            if(val[bi]>val[q[i].id+n])
            {
                cut(e[bi-n].u,bi);
                cut(e[bi-n].v,bi);
                link(q[i].x,q[i].id+n);
                link(q[i].y,q[i].id+n);
            }
        }
    }
    for(int i=1;i<=Q;++i)
        if(q[i].fl==1) printf("%d\n",q[i].ans);
    return 0;
}