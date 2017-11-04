#include <iostream>    
#include <cstdio>    
#include <cstring>    
#include <algorithm>    
#include <cmath>    
#include <queue>    
#include <string>    
#include <map>    
#include <cstring>    
#define INF 0x3f3f3f3f    
#define ms(x,y) memset(x,y,sizeof(x))    
using namespace std;  
  
typedef long long ll;  
typedef unsigned long long ull;  
typedef pair<int, int> P;  
  
const int maxn = 30010;  
const int mod = 998244353;  
  
#define lson l,m,rt<<1    
#define rson m+1,r,rt<<1|1    
  
struct node {  
    ll v;  
    int id;  
};  
  
bool cmp(node a, node b)  
{  
    return a.v < b.v;  
}  
  
int posa[maxn], posb[maxn], ban[maxn];  
ll w1[maxn], w2[maxn], w3[maxn], f[maxn];  
node a[maxn], b[maxn];  
  
void cal(int i)  
{  
    w1[i] = w2[i] = w3[i] = -INF;  
    ll t1 = -INF, t2 = -INF;  
    if (i >= 1 && ban[i] != i)
    	w1[i] = a[i].v*b[i].v;  
    if (i >= 2 && ban[i] != i - 1 && ban[i - 1] != i)
    	w2[i] = a[i].v*b[i - 1].v + a[i - 1].v*b[i].v;  
    if (i >= 3 && ban[i] != i - 2 && ban[i - 1] != i&&ban[i - 2] != i - 1)
    	t1 = a[i].v*b[i - 2].v + a[i - 1].v*b[i].v + a[i - 2].v*b[i - 1].v;  
    if (i >= 3 && ban[i] != i - 1 && ban[i - 1] != i - 2 && ban[i - 2] != i)
    	t2 = a[i].v*b[i - 1].v + a[i - 1].v*b[i - 2].v + a[i - 2].v*b[i].v;  
    w3[i] = max(t1, t2);  
}  
  
int main()  
{  
    int n, q;  
    cin >> n >> q;  
    for (int i = 1; i <= n; i++)  
    {  
        cin >> a[i].v;  
        a[i].id = i;  
    }  
    for (int i = 1; i <= n; i++)  
    {  
        cin >> b[i].v;  
        b[i].id = i;  
    }  
    sort(a + 1, a + n + 1, cmp);  
    sort(b + 1, b + n + 1, cmp);  
    for (int i = 1; i <= n; i++)  
    {  
        posa[a[i].id] = i;  
        posb[b[i].id] = i;  
    }  
    for (int i = 1; i <= n; i++)  
    {  
        ban[i] = posb[a[i].id];  
    }  
    for (int i = 1; i <= n; i++)  
    {  
        cal(i);  
    }  
    for (int k = 0; k < q; k++)  
    {  
        int x, y;  
        cin >> x >> y;  
        x = posa[x], y = posa[y];  
        swap(ban[x], ban[y]);  
        for (int i = max(1, x - 5); i <= min(n, x + 5); i++) cal(i);  
        for (int i = max(1, y - 5); i <= min(n, y + 5); i++) cal(i);  
        f[0] = 0;  
        for (int i = 1; i <= n; i++)  
        {  
            f[i] = f[i - 1] + w1[i];  
            if (i >= 2) f[i] = max(f[i], f[i - 2] + w2[i]);  
            if (i >= 3) f[i] = max(f[i], f[i - 3] + w3[i]);  
        }  
        cout << f[n] << endl;  
    }  
    return 0;  
}  