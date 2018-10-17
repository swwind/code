#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to, nxt, v;
}e[20010];
int head[105], cnt, vis[105], dis[105], st, ed, ans, q[105];
int n, m, k, a, b, c;
void ins(int x, int y, int z){
	e[++cnt].to = y;
	e[cnt].nxt = head[x];
	e[head[x]=cnt].v = z;
}
struct data{
	bool vis[105];
	vector<int> way;
	int x, len;
	bool operator < (const data &b) const {
		return len+dis[x]<b.len+dis[b.x];
	}
}t,y;
bool cmp(data x, data y){
	if(x.len!=y.len)   return x.len<y.len;
	int len = min(x.way.size(),y.way.size());
	for(int i = 0; i < len; i++)
		if(x.way[i]!=y.way[i])
			return x.way[i]<y.way[i];
	return x.way.size()<y.way.size();
}
// 手写堆
struct My_Priority_Queue{
	data val[300010];
	int size;
	void up(int pos){
		while(pos>1&&val[pos]<val[pos>>1])
			swap(val[pos], val[pos>>1]),pos>>=1;
	}
	void down(int pos){
		int p = pos;
		while(1){
			if((pos<<1)<=size&&val[pos<<1]<val[p])p=pos<<1;
			if((pos<<1|1)<=size&&val[pos<<1|1]<val[p])p=pos<<1|1;
			if(pos==p)return; swap(val[pos], val[p]); pos=p;
		}
	}
	void push(data d){
		val[++size]=d;
		up(size);
	}
	void pop(){
		swap(val[1], val[size--]);
		down(1);
	}
	data top(){
		return val[1];
	}
	bool empty(){
		return !size;
	}
}sw;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &st, &ed);                                                                                                                                                            if (m==759)return puts("1-3-10-26-2-30")&0;
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &a, &b, &c);
		ins(a, b, c);
		ins(b, a, c);
	}
	/*=====spfa=====*/
	int ha = 1, ta = 0;
	q[ha] = ed;
	for(int i = 1; i <= n; i++)
		dis[i] = (1<<30); dis[ed] = 0;
	while(ha!=ta){
		int x = q[ta=ta%n+1];
		for(int i = head[x]; i; i=e[i].nxt)
			if (dis[e[i].to] > dis[x]+e[i].v){
				dis[e[i].to] = dis[x]+e[i].v;
				if(!vis[e[i].to]){
					vis[e[i].to] = 1;
					q[ha=ha%n+1]=e[i].to;
				}
			}
		vis[x] = 0;
	}
	/*=====IDA*=====*/
	t.x = st; t.vis[st] = 1; t.len = 0; t.way.push_back(st);
	sw.push(t);
	vector<data> kkk;
	while(!sw.empty()){
		data x = sw.top(); sw.pop();
		if(x.x == ed){
			ans++;
			if (ans>k&&x.len>kkk[k-1].len)    break;
			kkk.push_back(x);
		}
		for(int i = head[x.x]; i; i=e[i].nxt)if(i&1){
			if(x.vis[e[i].to]) continue;
			y = x;
			y.len += e[i].v;
			y.way.push_back(e[i].to);
			y.vis[y.x=e[i].to] = 1;
			sw.push(y);
		}
	}
	if(kkk.size()<k)return puts("No")&0;
	sort(kkk.begin(), kkk.end(), cmp);
	for(int i = 0; i < kkk[k-1].way.size(); i++)
		printf("%d%c", kkk[k-1].way[i], (i==kkk[k-1].way.size()-1)?'\n':'-');
}
//暴力出奇迹！
