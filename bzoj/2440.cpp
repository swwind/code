#include <bits/stdc++.h>
using namespace std;
long long mu[50020], pri[50020];
bool mark[50020];
inline long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long calc(long long x){
    long long sum = 0;
    int t = sqrt(x);
    for(int i = 1; i <= t; i++)
        sum += x/(i*i)*mu[i];
    return sum;
}
int main(){
    int T = read(), n, cnt = 0;
    mu[1] = 1;
    for(int i = 2; i <= 50000; i++){
        if(!mark[i]) pri[++cnt] = i, mu[i] = -1;
        for(int j = 1; j <= cnt && pri[j]*i <= 50000; j++){
            mark[pri[j]*i] = 1;
            if(i%pri[j]) mu[i*pri[j]] = -mu[i];
            else{mu[i*pri[j]] = 0; break;}
        }
    }
    while(T--){
        n = read();
        long long l = n, r = 1644934081LL, ans;
        while(l <= r){
            long long mid = l + r >> 1;
            if(calc(mid)>=n) ans = mid, r = mid-1;
            else l = mid+1;
        }
        printf("%lld\n", ans);
    }
}