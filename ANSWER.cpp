#include<iostream>
#include<cstdio>
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

const int maxn = 1E5 + 10;
typedef long long LL;
const LL INF = 1E16;

int n;
LL u[maxn],d[maxn],g[maxn],f[maxn][2];

inline int getint()
{
    char ch = getchar(); int ret = 0;
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9')
        ret = ret * 10 + ch - '0',ch = getchar();
    return ret;
}

int main()
{
    #ifdef DMC
        freopen("DMC.txt","r",stdin);
    #endif

    n = getint();
    for (int i = 1; i <= n; i++) u[i] = getint();
    for (int i = 1; i <= n; i++) d[i] = getint(),g[i] = u[i] - d[i];
    for (int i = 2; i <= n; i++)
    {
        if (u[i - 1] > u[i] && d[i - 1] < d[i]) {puts("-1"); return 0;}
        if (u[i] <= d[i - 1] || d[i] >= u[i - 1]) {puts("-1"); return 0;}
    }

    f[1][1] = INF;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = f[i][1] = INF;
        if (f[i - 1][0] != INF)
        {
            if (d[i - 1] >= d[i]) f[i][0] = min(f[i][0],f[i - 1][0]);
            if (u[i - 1] <= u[i]) f[i][1] = min(f[i][1],f[i - 1][0] + g[i - 1]);
        }
        if (f[i - 1][1] != INF)
        {
            if (u[i - 1] <= u[i]) f[i][1] = min(f[i][1],f[i - 1][1]);
            if (d[i - 1] >= d[i]) f[i][0] = min(f[i][0],f[i - 1][1] + g[i - 1]);
        }
    }
    cout << min(f[n][0],f[n][1] + g[n]) << endl;
    return 0;
}