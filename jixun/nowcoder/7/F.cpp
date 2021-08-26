
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,Ans;
int R_Int(){
    int ch,a;
    while(ch=getchar(),ch<'0'||ch>='9');a=(ch^48);
    while(ch=getchar(),ch>='0'&&ch<='9')a=a*10+(ch^48);
    return a;
}
 
struct Edge{int to,nxt;};
int dfn[maxn],sz[maxn],ti;
 
namespace T1{
    int h[maxn];
    Edge e[maxn<<1];int tot_Edge;
    void AddEdge(int from,int to){
        e[++tot_Edge]=(Edge){to,h[from]};
        h[from]=tot_Edge;
    }
    struct Node{
        Node():lch(0),rch(0),Mx(0),Add(0){}
        Node *lch,*rch;
        int Mx,Add;
    }node[maxn*40];int tot_Node;
    Node *Root[maxn];
    void Build(Node *&u,int le,int ri){
        u=&(node[++tot_Node]=Node());
        if(le==ri)return;
        int mid=(le+ri)>>1;
        Build(u->lch,le,mid);
        Build(u->rch,mid+1,ri);
    }
    void Update(Node *&u,int le,int ri,int l,int r,int val){
        if(l>ri||r<le)return;
        u=&(node[++tot_Node]=(u?(*u):Node()));
        u->Mx=max(u->Mx,val);
        if(l<=le&&ri<=r)return u->Add=max(u->Add,val),void();
        int mid=(le+ri)>>1;
        Update(u->lch,le,mid,l,r,val);
        Update(u->rch,mid+1,ri,l,r,val);
    }
    int Query(Node *u,int le,int ri,int l,int r){
        if(u==NULL)return 0;
        if(l>ri||r<le)return 0;
        if(l<=le&&ri<=r)return u->Mx;
        int mid=(le+ri)>>1;
        int ret=max(Query(u->lch,le,mid,l,r),Query(u->rch,mid+1,ri,l,r));
        return max(ret,u->Add);
    }
    void dfs(int u,int prt,int dep,int Mx){
        int L=dfn[u],R=dfn[u]+sz[u]-1;
        Root[u]=Root[prt];
        Mx=max(Query(Root[u],1,n,L,R),Mx);
        // printf("dfs %d %d %d [%d %d] %d Ans = %d\n",u,prt,dep,L,R,Mx,dep-Mx);
        Ans=max(Ans,dep-Mx);
        Update(Root[u],1,n,L,R,dep);
        for(int i=h[u];i;i=e[i].nxt)if(e[i].to!=prt){
            int v=e[i].to;
            dfs(v,u,dep+1,Mx);
        }
    }
    void Clear(){
        memset(h,0,sizeof(int)*(n+3));
        memset(Root,0,sizeof(int)*(n+3));
        tot_Edge=0;
        tot_Node=0;
        Ans=0;
    }
}
namespace T2{
    int h[maxn];
    Edge e[maxn<<1];int tot_Edge;
    void AddEdge(int from,int to){
        e[++tot_Edge]=(Edge){to,h[from]};
        h[from]=tot_Edge;
    }
    void dfs(int u,int prt){
        dfn[u]=++ti;
        sz[u]=1;
        for(int i=h[u];i;i=e[i].nxt)if(e[i].to!=prt){
            int v=e[i].to;
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
    void Clear(){
        memset(h,0,sizeof(int)*(n+3));
        tot_Edge=0;
        ti=0;
    }
}
int main(){
    int T;
    T=R_Int();
    while(T--){
        n=R_Int();
        for(int i=1,u,v;i<n;i++){
            u=R_Int(),v=R_Int();
            T1::AddEdge(u,v);
            T1::AddEdge(v,u);
        }
        for(int i=1,u,v;i<n;i++){
            u=R_Int(),v=R_Int();
            T2::AddEdge(u,v);
            T2::AddEdge(v,u);
        }
        T2::dfs(1,0);
        // T1::Build(T1::Root[0],1,n);
        // for(int i=1;i<=n;i++)printf("%d ",dfn[i]);puts("");
        // for(int i=1;i<=n;i++)printf("%d ",sz[i]);puts("");
        T1::dfs(1,0,1,0);
        cout<<Ans<<endl;
        T1::Clear();
        T2::Clear();
    }
    return 0;
}