/**************************************************************
    Problem: 1008
    User: SW_Wind
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1288 kb
****************************************************************/
 
#include <bits/stdc++.h>
#define MOD 100003
#define ll long long
using namespace std;
ll m, n;
ll sqr(ll a){
    return a*a%MOD;
}
ll mi(ll a, ll b){
    if(!b) return 1;
    if(b&1) return sqr(mi(a, b>>1)) * a % MOD;
    else return sqr(mi(a, b>>1));
}
int main(){
    scanf("%lld%lld", &m, &n);
    printf("%lld", (mi(m, n)-m*mi(m-1, n-1)%MOD+MOD)%MOD);
    return 0;
}

