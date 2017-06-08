#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x, y, id;
}a[N];
struct edge{
	int to, nxt;
	ll val;
}e[N<<2];
struct qq{
	int to;
	ll val;
	bool operator < (const qq &b) const {
		return val > b.val;
	}
};
priority_queue<qq> q;
int head[N], cnt;
ll dis[N];
bool cmp1(node a, node b){
	return a.x < b.x;
}
bool cmp2(node a, node b){
	return a.y < b.y;
}
void ins(int x, int y, ll z){
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z}; head[y] = cnt;
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++){
		a[i].x = read(); a[i].y = read();
		a[i].id = i;
	}
	sort(a+1, a+n+1, cmp1);
	for(int i = 1; i < n; i++) if(a[i+1].x-a[i].x <= abs(a[i].y-a[i+1].y))
		ins(a[i].id, a[i+1].id, a[i+1].x-a[i].x);
	sort(a+1, a+n+1, cmp2);
	for(int i = 1; i < n; i++) if(a[i+1].y-a[i].y <= abs(a[i].x-a[i+1].x))
		ins(a[i].id, a[i+1].id, a[i+1].y-a[i].y);
	memset(dis, 127/3, sizeof dis);
	dis[1] = 0;
	q.push((qq){1, 0});
	while(!q.empty()){
		qq tmp = q.top(); q.pop();
		if(dis[tmp.to] != tmp.val) continue;
		for(int i = head[tmp.to]; i; i = e[i].nxt){
			if(dis[e[i].to] > dis[tmp.to]+e[i].val){
				dis[e[i].to] = dis[tmp.to]+e[i].val;
				q.push((qq){e[i].to, dis[e[i].to]});
			}
		}
	}
	printf("%lld\n", dis[n]);
}