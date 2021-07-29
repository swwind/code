#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int tr(int S,int mv){
    if(!mv)return S|1;
    int ret=0;
    if(mv==1){
        ret|=(S&1)<<1;
        ret|=((S>>1)&1)<<2;
        ret|=((S>>2)&1);
        ret|=1<<1;
    }
    else{
        ret|=(S&1)<<2;
        ret|=((S>>1)&1);
        ret|=((S>>2)&1)<<1;
        ret|=1<<2;
    }
    return ret;
}
bool Check(int n){
    int S=0;
    while(n){
        S=tr(S,(n%10)%3);
        if(S&1)return 1;
        n/=10;
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL L,R;
        scanf("%lld%lld",&L,&R);
        if(L<100){
            LL Ans=0;
            if(R>100)Ans+=R-100;
            for(int i=L;i<=min(100ll,R);i++)Ans+=Check(i);
            printf("%lld\n",Ans);
        }
        else printf("%lld\n",R-L+1);
    }
    return 0;
}