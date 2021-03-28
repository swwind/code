#include <cstdio>
#include <algorithm>
#include <queue>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int a[N];
queue<int> q;

int main() {

  int st = read(), ed = read();
  int n = 500000;
  q.push(st);
  while (!q.empty()) {
    int s = q.front(); q.pop();
    if (s-1 >= 1 && !a[s - 1] && s-1!=st) a[s - 1] = a[s] + 1, q.push(s - 1);
    if (s+1 <= n && !a[s + 1] && s+1!=st) a[s + 1] = a[s] + 1, q.push(s + 1);
    if ((s<<1) <= n && !a[s<<1] && (s<<1)!=st) a[s<<1] = a[s] + 1, q.push(s<<1);
  }
  printf("%d\n", a[ed]);
}
