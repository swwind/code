#include<stdio.h>  
#include<algorithm>  
using namespace std;  
#define LL long long  
#define mod 10000007  
LL C[88][88], a[88], sum[88];  
LL Pow(LL a, LL b)  
{  
    LL ans;  
    ans = 1;  
    while(b)  
    {  
        if(b%2==1)  
            ans = (ans*a)%mod;  
        a = (a*a)%mod;  
        b /= 2;  
    }  
    return ans;  
}  
int main(void)  
{  
    LL i, j, n, ans, len, now;  
    for(i=0;i<=66;i++)  
        C[i][0] = 1;  
    for(i=1;i<=66;i++)  
    {  
        for(j=1;j<=i;j++)  
            C[i][j] = C[i-1][j-1]+C[i-1][j];  
    }  
    scanf("%lld", &n);  
    len = 0;  
    while(n)  
    {  
        a[++len] = n%2;  
        n /= 2;  
    }  
    reverse(a+1, a+len+1);  
    now = 0;  
    for(i=1;i<=len;i++)  
    {  
        if(a[i])  
        {  
            printf("%d\n", len-i);
            for(j=0;j<=len-i;j++)   
                sum[now+j] += C[len-i][j];  
            sum[now]--;  
            sum[++now]++;  
        }  
    }  
    ans = 1;  
    for(i=1;i<=66;i++)  {
        printf("%lld\n", sum[i]);
        ans = (ans*Pow(i, sum[i]))%mod;  
    }
    printf("%lld\n", ans);  
}  