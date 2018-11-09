
// Copy from luogu1169

#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h> 
#include <queue>
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <set>
#include <map>
#include <fstream>
#include <bits/stdc++.h>
#define ll long long
#define oo 1<<30
#define ESP 1e-9
#define read(a) scanf("%d", &a)
#define writeln(a) printf("%d\n", a)
#define write(a) printf("%d", a)
#define mst(a, b) memset(a, b, sizeof a)
#define rep(a, b, c) for(int a = b; a < c; a ++)
#define reps(a, b, c) for(int a = b; a <= c; a ++)
#define repx(a, b, c) for(int a = b, a > c; a --)
#define repxs(a, b, c) for(int a = b; a >= c; a --)
#define MOD 1000000007
#define MAXN 805

using namespace std;

const int mxn=2005;
int n,m,ans1,ans2;
int h[mxn][mxn],l[mxn],r[mxn],s[mxn];
bool a[mxn][mxn];

inline void find(bool flag)
{
    memset(h,0,sizeof h);
    reps(i,1,n) reps(j,1,m) if(a[i][j]==flag) h[i][j]=h[i-1][j]+1;
    reps( i,1,n)
    {
        int top=0;
        s[top]=0;
        reps( j,1,m)
        {
            while(h[i][s[top]]>=h[i][j] && top) top--;
            l[j]=s[top]+1; 
            s[++top]=j;
        }
        top=0;s[0]=m+1;
        repxs(j,m,1)
        {
            while(h[i][s[top]]>=h[i][j] && top) top--;
            r[j]=s[top]-1;
            s[++top]=j;
            ans2=max(ans2,(r[j]-l[j]+1)*h[i][j]);
            if(r[j]-l[j]+1>=h[i][j]) ans1=max(ans1,h[i][j]*h[i][j]);
        }
    }
}

int main (){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			cin >> a[i][j];
			a[i][j] = (a[i][j] == (i % 2) ^ (j % 2));
		}
	find(0);
	find(1);
	cout << ans1 << "\n" << ans2;
    return 0;
}