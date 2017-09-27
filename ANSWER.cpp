#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define inc(i,j,k) for(int i=j;i<=k;i++)
#define maxn 100010
using namespace std;
inline int read(){
    char ch=getchar(); int f=1,x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return f*x;
}
int sum[maxn][50],n,k,ans;
struct nd{
    int id; int num[50];
    bool operator < (const nd &a)const{inc(i,1,k-1)if(num[i]!=a.num[i])return num[i]<a.num[i]; return 0;}
};
multiset<nd>st; nd a;
int main(){
    n=read(); k=read();
    inc(i,1,n){
        int x=read(); inc(j,1,k)sum[i][j]=sum[i-1][j]; for(int j=k-1;j>=0;j--)if(x&(1<<j))sum[i][j+1]++;
    }
    inc(j,1,k-1)a.num[j]=0; a.id=0; st.insert(a);
    inc(i,1,n){
        inc(j,1,k-1)a.num[j]=sum[i][j]-sum[i][j+1]; a.id=i;
        multiset<nd>::iterator sti=st.find(a); if(sti==st.end())st.insert(a);else{
            ans=max(ans,i-sti->id);
        }
    }
    printf("%d",ans); return 0;
}