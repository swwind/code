#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define M 200005
using namespace std;
int num=0,ans=0,n,m,tot,h[M],f[M],low[M],dfn[M],q[M],a[M],fa[M];
struct edge
{
	int y,ne;
}e[M];
void Addedge(int x,int y)
{
	tot++;
	e[tot].y=y;
	e[tot].ne=h[x];
	h[x]=tot;
}
void dp(int x,int y)
{
	printf("%d %d\n", x,y);
	int m=0;
	while (y!=x)
	{
		a[++m]=f[y];
		y=fa[y];
	}
	a[++m]=f[x];
	for (int i=1;i<m;i++)
		a[m+i]=a[i];
	int l,r;
	int p=m/2;
	q[l=r=1]=1;
	for (int i=2;i<=m+p;i++)
	{
		while (l<=r&&i-q[l]>p)
			l++;
		ans=max(ans,a[q[l]]+a[i]+i-q[l]);
		while (l<=r&&a[q[r]]+i-q[r]<=a[i])
			r--;
		q[++r]=i;
	}
	for (int i=1;i<m;i++)
		f[x]=max(f[x],a[i]+min(i,m-i));
}
void tarjan(int x)
{
	printf("%d\n", x);
	dfn[x]=low[x]=++num;
	for (int i=h[x];i;i=e[i].ne)
		if (fa[x]!=e[i].y)
		{
			if (!dfn[e[i].y])
			{
				int y=e[i].y;
				fa[y]=x;
				tarjan(y);
				low[x]=min(low[x],low[y]);
				if (dfn[x]<low[y])
				{
					ans=max(ans,f[x]+f[y]+1);
					f[x]=max(f[x],f[y]+1);
				}
			}
			else low[x]=min(low[x],dfn[e[i].y]);
		}
	for (int i=h[x];i;i=e[i].ne)
		if (fa[e[i].y]!=x&&dfn[x]<dfn[e[i].y])
			dp(x,e[i].y);
		printf("%d\n", ans);
}
int main()
{
		scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int k,x,y;
		scanf("%d%d",&k,&x);
		for (int j=1;j<k;j++)
		{
			scanf("%d",&y);
			Addedge(x,y),Addedge(y,x);
			x=y;
		}
	}
	tarjan(1);
	cout<<ans<<endl;
	return 0;
}