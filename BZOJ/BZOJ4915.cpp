#include <bits/stdc++.h>
using namespace std;
int main(){
    long long l,r;scanf("%lld%lld",&l,&r);
    long long x1=r/11-l+1,x2=r/29-l+1;
    printf("4\n%lld\n",(x1<0?0:x1)+(x2<0?0:x2));
}
