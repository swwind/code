#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	int p, x;
	bool flag;
	bool operator < (const node &b) const {
		return p < b.p;
	}
}q[N];
__gnu_pbds::priority_queue<int>h;
__gnu_pbds::priority_queue<int>::point_iterator it[N];
set<int>bit;
int main(int argc, char const *argv[]){
	int n = read(), cnt = 0;
	for(int i = 1; i <= n; i++){
		q[++cnt] = (node){read(), i, 1};
		q[++cnt] = (node){read()+1, i, 0};
	}
	sort(q+1, q+cnt+1);
	for(int i = 1; i <= cnt; i++){
		if(!h.empty() && q[i].p != q[i-1].p) bit.insert(h.top());
		if(q[i].flag) it[q[i].x] = h.push(q[i].x);
		else h.erase(it[q[i].x]);
	}
	printf("%d\n", bit.size());
	return 0;
}
