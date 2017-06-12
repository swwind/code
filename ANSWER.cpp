#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#define N 1000003  
#define LL long long  
using namespace std;  
int n,m,cnt,root,last,np,nq,p,q;  
int ch[N][30],fa[N],l[N],a[N],v[N],r[N],pos[N];  
LL sum[N];  
char s[N];  
void extend(int x)  
{  
    int c=a[x];  
    p=last; np=++cnt; last=np;  
    l[np]=x;  
    for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;  
    if (!p) fa[np]=root;  
    else {  
        q=ch[p][c];  
        if (l[q]==l[p]+1) fa[np]=q;  
        else {  
            nq=++cnt; l[nq]=l[p]+1;  
            memcpy(ch[nq],ch[q],sizeof ch[nq]);  
            fa[nq]=fa[q];  
            fa[q]=fa[np]=nq;  
            for (;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;  
        }  
    }  
}  
int main()  
{  
    // freopen("a.in","r",stdin);  
    // freopen("my.out","w",stdout);  
    scanf("%s",s+1);  
    n=strlen(s+1);  
    last=root=++cnt;  
    for (int i=1;i<=n;i++) a[n-i+1]=s[i]-'a';  
    for (int i=1;i<=n;i++) extend(i);  
    for (int i=1;i<=cnt;i++) v[l[i]]++;  
    for (int i=1;i<=n;i++) v[i]+=v[i-1];  
    for (int i=1;i<=cnt;i++) pos[v[l[i]]--]=i;  
    p=1;   
    for (int i=1;i<=n;i++) {  
        p=ch[p][a[i]]; r[p]++; sum[p]++;  
    }  
    for (int i=cnt;i;i--){  
        int t=pos[i];  
        r[fa[t]]+=r[t];  
    }  
    /*for (int i=1;i<=cnt;i++) cout<<r[i]<<" "; 
    cout<<endl; 
    for (int i=1;i<=cnt;i++) cout<<l[i]<<" "; 
    cout<<endl; 
    for (int i=1;i<=cnt;i++) cout<<pos[i]<<" "; 
    cout<<endl;*/  
    LL ans=0;  
    for (int i=cnt;i>=1;i--){  
        int t=pos[i];  
        ans+=(LL)l[fa[t]]*(LL)r[t]*(LL)sum[fa[t]];  
        sum[fa[t]]+=(LL)r[t];  
    }  
//  cout<<ans<<endl;  
    printf("%I64d\n",(LL)(n+1)*(LL)n/2*(LL)(n-1)-2*ans);  
}  