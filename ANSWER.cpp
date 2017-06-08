//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 1000001
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
const int inf=0x3f3f3f3f;
inline ll read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void P(int x)
{
	Num=0;if(!x){putchar('0');puts("");return;}
	while(x>0)CH[++Num]=x%10,x/=10;
	while(Num)putchar(CH[Num--]+48);
	puts("");
}
char s[2*maxn];
int n;
int sa[maxn],ra[maxn],tmp[maxn],height[maxn];
int top[maxn+10];
void build_sa()
{
	int m = 128; // 最大字符值
	int *x = ra, *y = tmp; // x 第一关键字 y 备份
	// 对单个字符进行基数排序
	for(int i = 0; i < m; i++) top[i] = 0;
	for(int i = 0; i < n; i++) top[x[i]=s[i]]++;
	for(int i = 1; i < m; i++) top[i] += top[i-1];
	for(int i = n-1; i >= 0; i--) sa[--top[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1) {
		int p = 0;
		// 利用上一次的sa值算出第二关键字的排序
		for(int i = n - k; i < n; i++) y[p++] = i;
		for(int i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
		// 对第一关键字进行基数排序
		for(int i = 0; i < m; i++) top[i] = 0;
		for(int i = 0; i < n; i++) top[x[y[i]]]++;
		for(int i = 0; i < m; i++) top[i] += top[i-1];
		for(int i = n-1; i >= 0; i--) sa[--top[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		// 计算rank值
		for(int i = 1; i < n; i++)
			x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) ? p-1 : p++;
		if(p >= n) break;
		m = p;
	}
}
void build_height(){
	//rep (i,0,n) rank[sa[i]] = i;
	int k = 0;
	for(int i=0;i<n;i++) ra[sa[i]] = i;
	for(int i=0;i<n;i++){
		if (k) k--;
		int j = sa[ra[i] - 1];
		while (s[i+k] == s[j+k]) k++;
		height[ra[i]] = k;
	}
}
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for(int i=len;i<2*len;i++) s[i] = s[i-len];
	n = 2*len;
	build_sa();
	for(int i=1;i<n;i++)
	{
		if (sa[i] < len)
		{
			putchar(s[sa[i]+len-1]);
		}
	}
	puts("");
}