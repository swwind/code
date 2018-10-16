#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[400020];
int main(int argc, char const *argv[]){
	int n = read(), ans = 0;
	for(int i = 1; i <= n; i++) a[i] = read();
	a[0] = a[n+1] = 1<<30;
	while(n > 1){
		int k = 1;
		while(k <= n) if(a[k-1] <= a[k+1]) break; else k++;
		int f = a[k-1] += a[k];
		for(int i = k; i <= n; i++) a[i] = a[i+1];
		int pk = k-2;
		while(~pk) if(a[pk] > f) break; else pk--;
		int g = a[k-1];
		for(int i = k-1; i > pk; i--) a[i] = a[i-1];
		a[pk+1] = g; ans += f; n--;
	}
	printf("%d\n", ans);
	return 0;
}
/*
个人认为还是比较简单的(在知道了GarsiaWachs算法后）

我只知道结论，设一个序列是A[0..n-1]，每次寻找最小的一个满足A[k-1]<=A[k+1]的k，
（方便起见设A[-1]和A[n]等于正无穷大）

那么我们就把A[k]与A[k-1]合并，之后找最大的一个满足A[j]>A[k]+A[k-1]的j,
把合并后的值A[k]+A[k-1]插入A[j]的后面。
有定理保证，如此操作后问题的答案不会改变。
举个例子：
186 64 35 32 103
因为35<103，所以最小的k是3，我们先把35和32删除，得到他们的和67，
并向前寻找一个第一个超过67的数，把67插入到他后面
186 64（k=3,A[3]与A[2]都被删除了） 103
186 67（遇到了从右向左第一个比67大的数，我们把67插入到他后面） 64 103
186 67 64 103 （有定理保证这个序列的答案加上67就等于原序列的答案）
现在由5个数变为4个数了，继续！
186 （k=2,67和64被删除了）103
186 131（就插入在这里） 103
186 131 103
现在k=2（别忘了，设A[-1]和A[n]等于正无穷大）
234 186
420
最后的答案呢？就是各次合并的重量之和呗。420+234+131+67=852；
*///:~