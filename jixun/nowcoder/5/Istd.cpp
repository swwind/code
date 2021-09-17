#include<bits/stdc++.h>
using namespace std;
#define M 200005
#define P 998244353
int ans,len,A[M],sz[M],n,m,Mx[M],base[M],B[M];
struct node{
    int kuai,l,r,id,k;
    bool operator <(const node &tmp)const{
        if(kuai!=tmp.kuai)return kuai<tmp.kuai;
        return r<tmp.r;
    }
}Q[M],stk[M];
int top,res[M];
void chk(int &a,int b){
    a+=b;
    if(a>=P)a-=P;
}
void add(int x,int id){
    x=A[x];
    if(sz[x])return;
    if(id){
        ++top;
        stk[top].id=x;
        stk[top].l=stk[top].r=-1;
    }
    B[x]=x;
    sz[x]=1;
    if(sz[x]>len)len=sz[x];
    if(sz[x-1]){
        int l=B[x-1],r=B[x];
        B[l]=r;
        B[r]=l;
        if(id)stk[top].l=sz[x-1];
        sz[l]=sz[x-1]+sz[x];
        sz[r]=sz[l];
        if(sz[l]>len)len=sz[l];
    }
    if(sz[x+1]){
        int l=B[x],r=B[x+1];
        B[l]=r;
        B[r]=l;
        if(id)stk[top].r=sz[x+1];
        sz[l]=sz[x]+sz[x+1];
        sz[r]=sz[l];
        if(sz[l]>len)len=sz[l];
    }
}
void pop(){
    while(top){
        int now=stk[top].id;
        if(~stk[top].l){
            sz[now-1]=stk[top].l;
            int l=B[now-1];
            if(l>now-1)l=now-1;
            sz[l]=sz[now-1];
            B[l]=now-1;
        }
        if(~stk[top].r){
            sz[now+1]=stk[top].r;
            int r=B[now+1];
            if(r<now+1)r=now+1;
            sz[r]=sz[now+1];
            B[r]=now+1;
        }
        sz[now]=0;
        B[now]=0;
        top--;
    }
}
int main(){
    int i,j,l,r,k,id;
    scanf("%d %d",&n,&m);
    base[0]=1;
    for(i=1;i<=n;i++)base[i]=1LL*base[i-1]*(n+1)%P;
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    int sqr=sqrt(n);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&l,&r,&k);
        id=l/sqr;
        Mx[id]=max(Mx[id],l);
        Q[i].l=l;
        Q[i].r=r;
        Q[i].id=i;
        Q[i].kuai=id;
        Q[i].k=k;
    }
    sort(Q+1,Q+m+1);
    Q[0].kuai=-1;
    for(i=1;i<=m;i++){
        ans=0;
        if(Q[i].kuai!=Q[i-1].kuai){
            for(j=1;j<=n;j++){
                sz[j]=0;
                B[j]=0;
            }
            len=0;
            //[Mx,r]
            l=Mx[Q[i].kuai];
            r=l-1;
        }
        if(Q[i].r<l){
            len=0;
            for(j=Q[i].l;j<=Q[i].r;j++){
                add(j,1);
            }
            chk(ans,1LL*len*base[0]%P);
            for(j=1;j<Q[i].k;j++){
                add(Q[i].l-j,1);
                add(Q[i].r+j,1);
                chk(ans,1LL*len*base[j]%P);
            }
            res[Q[i].id]=ans;
            pop();
            len=0;
            continue;
        }
        while(r<Q[i].r)add(++r,0);
        int pre=len;
        for(j=Mx[Q[i].kuai]-1;j>=Q[i].l;j--)add(j,1);
        chk(ans,1LL*len*base[0]%P);
        for(j=1;j<Q[i].k;j++){
            add(Q[i].l-j,1);
            add(Q[i].r+j,1);
            chk(ans,1LL*len*base[j]%P);
        }
        pop();
        res[Q[i].id]=ans;
        len=pre;
    }
    for(i=1;i<=m;i++)
        printf("%d\n",res[i]);
    return 0;
}
/*
20 3
2 4 1 5 3 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
5 5 2
7 8 7
10 10 10
*/