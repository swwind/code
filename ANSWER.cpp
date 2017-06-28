#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define MOD 1000000007  
using namespace std;  
typedef long long ll;  
struct Matrix{  
    ll xx[2][2];  
    Matrix(ll _,ll __,ll ___,ll ____)  
    {  
        xx[0][0]=_;  
        xx[0][1]=__;  
        xx[1][0]=___;  
        xx[1][1]=____;  
    }  
    ll* operator [] (int x)  
    {  
        return xx[x];  
    }  
};  
ll f[70],g[70];  
void operator *= (Matrix &x,Matrix &y)  
{  
    int i,j,k;  
    Matrix z(0,0,0,0);  
    for(i=0;i<2;i++)  
        for(j=0;j<2;j++)  
            for(k=0;k<2;k++)  
                z[i][j]+=x[i][k]*y[k][j],z[i][j]%=MOD;  
    x=z;  
}  
ll Digital_DP(ll x)  
{  
    int i,temp=0;  
    long long re=0;  
    for(i=0;1ll<<i<=x;i++);  
    for(;i;i--)  
    {  
        if( x&(1ll<<i-1) )  
        {  
            re+=f[i];  
            if(temp) return re-1;  
            temp=1;  
        }  
        else  
            temp=0;  
    }  
    return re-1;  
}  
ll Matrix_Mutiplication(ll y)  
{  
    Matrix a(1,0,0,1),x(0,1,1,1);  
    while(y)  
    {  
        if(y&1) a*=x;  
        x*=x;  
        y>>=1;  
    }  
    printf("%lld %lld %lld %lld\n", a[0][0], a[0][1], a[1][0], a[1][1]);
    return (a[0][1]+a[1][1])%MOD;  
}  
int main()  
{  
    int T,i;ll x;  
    f[0]=1;  
    for(i=1;i<=63;i++)  
        f[i]=f[i-1]+g[i-1],g[i]=f[i-1];  
    for(cin>>T;T;T--)  
    {  
        scanf("%lld",&x);  
        printf("%lld\n", Digital_DP(x+1) );  
        printf("%lld\n", Matrix_Mutiplication(x) );  
    }  
}  