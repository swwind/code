#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 100005
struct node{
    ll l,r,al,ar,h;
}pl[maxn];
bool cmp(node x,node y){
    return(x.h<y.h);    
}
ll a[maxn<<1],n,m,mx,N;
ll f[maxn][2],p[maxn][2];
ll se[maxn*9],le,ri,v,beg;
inline ll mabs(ll x){ return(x>0?x:-x); }
inline void pushdown(ll o){
    if(se[o]){
       ll lc=o<<1,rc=(o<<1)|1;
       se[lc]=se[rc]=se[o];
       se[o]=0;
    }
}
void update(ll o,ll l,ll r){
    if(l>=le&&r<=ri){
        se[o]=v;
        return;
    }
    pushdown(o);
    ll mid=l+r>>1,lc=o<<1,rc=(o<<1)|1;
    if(le<=mid) update(lc,l,mid);
    if(ri>mid) update(rc,mid+1,r);
}
ll query(ll o,ll l,ll r){
    if(se[o]) return se[o];
    if(l==r) return 0;
    ll mid=l+r>>1,lc=o<<1,rc=(o<<1)|1;
    if(le<=mid) return query(lc,l,mid);
    else return query(rc,mid+1,r);    
}
ll dp(ll x,ll pos){
    if(p[x][pos]) return p[x][pos];
    ll now=(pos?pl[x].r:pl[x].l);
    p[x][pos]=(ll)(1<<30);
    if(!f[x][pos]) p[x][pos]=min(p[x][pos],(ll)0);
    else if(f[x][pos]>0) p[x][pos]=min(p[x][pos],min(dp(f[x][pos],0)+mabs(now-pl[f[x][pos]].l),dp(f[x][pos],1)+mabs(now-pl[f[x][pos]].r)));
    return p[x][pos];
}
int main(){
    cin>>n>>mx;
    n++;
    scanf("%lld%lld",&pl[n].l,&pl[n].h),pl[n].r=pl[n].l;
    a[1]=pl[n].l;
    for(int i=1;i<n;i++){
        scanf("%lld%lld%lld",&pl[i].h,&pl[i].l,&pl[i].r);
        a[i<<1]=pl[i].l,a[(i<<1)|1]=pl[i].r;
    }
    N=(n<<1)-1;
    sort(a+1,a+N+1);
    for(int i=1;i<=n;i++) pl[i].al=lower_bound(a+1,a+N+1,pl[i].l)-a,pl[i].ar=lower_bound(a+1,a+N+1,pl[i].r)-a;
    sort(pl+1,pl+n+1,cmp);
    pl[0].h=0;
    for(int i=1;i<=n;i++){
        le=pl[i].al;
        f[i][0]=query(1,1,N);
        if(pl[i].h-pl[f[i][0]].h>mx) f[i][0]=-1;
        le=pl[i].ar;
        f[i][1]=query(1,1,N);
        if(pl[i].h-pl[f[i][1]].h>mx) f[i][1]=-1;
        if(pl[i].l==pl[i].r) beg=i;        
        ri=le,le=pl[i].al,v=i;
        update(1,1,N);
    }
    printf("%lld\n",dp(beg,0)+pl[beg].h);
    return 0;
}