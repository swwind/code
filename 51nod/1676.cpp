#include <bits/stdc++.h>
#define N 220
#define M 4020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int head1[N], nxt1[M<<1], to1[M<<1], cnt1;
void ins1(int x, int y){
	to1[++cnt1] = y; nxt1[cnt1] = head1[x]; head1[x] = cnt1;
	to1[++cnt1] = x; nxt1[cnt1] = head1[y]; head1[y] = cnt1;
}
int head2[N], nxt2[M<<1], to2[M<<1], cnt2;
void ins2(int x, int y){
	to2[++cnt2] = y; nxt2[cnt2] = head2[x]; head2[x] = cnt2;
	to2[++cnt2] = x; nxt2[cnt2] = head2[y]; head2[y] = cnt2;
}
struct node{
	int id, v;
	friend bool operator < (const node &a, const node &b){
		return a.v < b.v;
	}
}a1[2][N], a2[2][N];
int p1[N], p2[N];
int main(int argc, char const *argv[]){
	int T = read();
	while(T--){
		cnt1 = cnt2 = 0;
		memset(head1, 0, sizeof(int)*N);
		memset(head2, 0, sizeof(int)*N);
		int n = read(), m = read();
		for(int i = 1; i <= m; i++) ins1(read(), read());
		for(int i = 1; i <= m; i++) ins2(read(), read());
		for(int i = 1; i <= n; i++){
			a1[0][i].v = a2[0][i].v = 1;
			ins1(i, i); ins2(i, i);
			p1[i] = a1[1][i].id = a1[0][i].id = i;
			p2[i] = a2[1][i].id = a2[0][i].id = i;
		}
		bool flag = 1;
		for(int it = 1, now = 1, pre = 0; it <= n; it++, now ^= 1, pre ^= 1){
			for(int i = 1; i <= n; i++) a1[now][i].v = a2[now][i].v = 0;
			for(int i = 1; i <= n; i++) p1[a1[now][i].id] = p2[a2[now][i].id] = i;
			for(int i = 1; i <= n; i++){
				for(int j = head1[a1[pre][i].id], k = a1[pre][i].v; j; j = nxt1[j])
					a1[now][p1[to1[j]]].v = a1[now][p1[to1[j]]].v*2333+k;
				for(int j = head2[a2[pre][i].id], k = a1[pre][i].v; j; j = nxt2[j])
					a2[now][p2[to2[j]]].v = a2[now][p2[to2[j]]].v*2333+k;
			}
			sort(a1[now]+1, a1[now]+n+1);
			sort(a2[now]+1, a2[now]+n+1);
			for(int i = 1; i <= n && flag; i++)
				if(a1[now][i].v != a2[now][i].v)
					flag = 0;
			if(!flag) break;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}