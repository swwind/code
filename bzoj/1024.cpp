#include <bits/stdc++.h>
#define ll long long
#define inf (1<<30)
using namespace std;
int x, y, n;
double work(double x, double y, int k){
    if(k == 1) return max(x,y)/min(x,y);
    double ans = inf;
    for(int i = 1; i < k; i++)
        ans = min(ans, max(work(x, y/k*i, i), work(x, y/k*(k-i), k-i)));
    for(int i = 1; i < k; i++)
        ans = min(ans, max(work(x/k*i, y, i), work(x/k*(k-i), y, k-i)));
    return ans;
}
int main(){
    scanf("%d%d%d", &x, &y, &n);
    printf("%.6lf", work(x, y, n));
    return 0;
}
