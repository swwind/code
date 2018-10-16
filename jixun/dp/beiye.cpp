#pragma GCC optimize 2
#include<cstdio> 
#include<ctime>
#include<memory.h>
#define N 1505
#define LG 12
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int min(int x,int y){	return x<y?x:y;	}
int lbc[70020], lg2[1540],htr;
struct bst {
	static const int BST_SIZE = 50;
	unsigned int a[BST_SIZE];
	bst(){	for(int i=0;i<BST_SIZE;i++)	a[i]=0;	}
	void set(){	for(int i=0;i<BST_SIZE;i++)	a[i]=-1;	}
	bool operator [] (int x) {
		return a[x >> 5] >> (x & 31) & 1;
	}
	inline void set1(int x) {
		a[x >> 5] |= 1 << (x & 31);
	}
	void andw (const bst &b,const bst &c,ll w) {
		int i=0;
		for(;i<BST_SIZE-w;i++)	a[i]&=b.a[i]&c.a[i];
		htr=min(htr,BST_SIZE-w);
	}
	friend bst operator & (const bst &a, const bst &b) {
		bst c;
		for (int i = 0; i < BST_SIZE; i++)
			c.a[i] = a.a[i] & b.a[i];
		return c;
	}
	bst operator >> (int b) {
		if (b == 0) return *this;
		 bst c;
		int l = b & 31, r = (b >> 5);
		for (int i = r, j = 0; i < BST_SIZE; i++, j++) {
			c.a[j] |= a[i] >> l;
			if (j && l) c.a[j - 1] |= a[i] << 32 - l;
		}
		return c;
	}
	inline int count() {
		int res = 0;
		for (int i = 0; i < htr; i++)
			res += lbc[a[i] & ((1 << 16) - 1)] + lbc[a[i] >> 16];
		return res;
	}
};
char ch[N][N];
bst a[32][N][LG], b[32][N][LG];
bst res;
void aska(int x, int w) {
	int t = lg2[w];
	res.andw(a[0][x][t],a[(w-(1<<t))&31][x][t],(w-(1<<t))>>5);
}
void askb(int x, int w,int d) {
	int t = lg2[w];
	res.andw(b[0][x][t],b[d&31][x][t],d>>5);
	res.andw(b[0][x+w-(1<<t)][t],b[d&31][x+w-(1<<t)][t],d>>5);
}int main(int argc, char const *argv[]) {

	int n = read(), q = read();
	for (int i = 1; i <= 70000; i++)
		lbc[i] = lbc[i ^ (i & -i)] + 1;
	lg2[1] = 0;
	for (int i = 2; i <= 1500; i++)
		lg2[i] = lg2[i >> 1] + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", ch[i] + 1);
		for (int j = 1; j <= n; j++)
			if (ch[i][j] == '1') {
				a[0][i][0].set1(j);
				b[0][i][0].set1(j);
			}
	}
	for (int x = 1; x <= n; x++)
		for (int i = 1; i < LG; i++)
			for (int j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
				if (a[0][x][i - 1][j] && a[0][x][i - 1][j + (1 << i - 1)])
					a[0][x][i].set1(j);
	for (int i = 1; i < LG; i++)
		for (int j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
			b[0][j][i] = b[0][j][i - 1] & b[0][j + (1 << i - 1)][i - 1];
	for(int cur=1;cur<32;cur++)	for(int x=0;x<=n;x++)	for(int i=0;i<LG;i++)	a[cur][x][i]=a[cur-1][x][i]>>1;
	for(int cur=1;cur<32;cur++)	for(int x=0;x<=n;x++)	for(int i=0;i<LG;i++)	b[cur][x][i]=b[cur-1][x][i]>>1;
	while (q --) {
		int y = read(), x = read(), ans = 0;
		for (int i = 1; i + y - 1 <= n; i++) {
			res.set();	htr=50;
			aska(i, x);
			aska(i + y - 1, x);
			askb(i, y , x - 1);
			ans = ans + res.count();
		}
		printf("%d\n", ans);
	}
	return 0;
}
