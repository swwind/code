#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define maxn 60001
#define inf (1ll<<62)
using namespace std;
long long _,type,k,np[maxn],ans,ca=0;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
void dfs(int kk,long long num,long long sum,long long limit)
{
    if (sum>k) return ;
    if (sum==k) ans=min(ans,num);
        for (int i=1;i<=limit;i++) {
            if (ans/p[kk] <num || sum*(i+1)>k) break;
            num*=p[kk];
            if (k%(sum*(i+1))==0)
                dfs(kk+1,num,sum*(i+1),i);
        }
}

int main()
{
    scanf("%lld",&_);
    int i,j;
    for (i=0;i<maxn;i++) np[i]=i;
    for (i=1;i<maxn;i++)
    {
        for (j=i;j<maxn;j+=i) np[j]--;
        if (!np[np[i]]) np[np[i]]=i;
        np[i]=0;
     }
    //for (i=1;i<=100;i++) cout<<np[i]<<endl;
    while (_--)
    {
        scanf("%lld%lld",&type,&k);
        if (type==1) ans=np[k]; else
        {
            ans=inf;
            dfs(0,1,1,62);
         }
        printf("Case %lld: ",++ca);
        if (ans==0) puts("Illegal"); else if (ans>=inf) puts("INF"); else
            printf("%lld\n",ans);
     }
    return 0;
 }