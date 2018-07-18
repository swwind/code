#include <bits/stdc++.h>
#define N 100020
#define ll long long
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct My_Priority_Queue{
  int val[7200000];
  int size;
  void up(int pos){
    while(pos>1&&val[pos]>val[pos>>1])
      std::swap(val[pos], val[pos>>1]),pos>>=1;
  }
  void down(int pos){
    int p = pos;
    while(1){
      if((pos<<1)<=size&&val[pos<<1]>val[p])p=pos<<1;
      if((pos<<1|1)<=size&&val[pos<<1|1]>val[p])p=pos<<1|1;
      if(pos==p)return; std::swap(val[pos], val[p]); pos=p;
    }
  }
  void push(int d){
    val[++size]=d;
    up(size);
  }
  void pop(){
    std::swap(val[1], val[size--]);
    down(1);
  }
  int top(){
    return val[1];
  }
  bool empty(){
    return !size;
  }
}queue;
int main(int argc, char const *argv[]) {
  int n = read(), m = read(), q = read(), u = read(), v = read(), t = read();
  for (int i = 1; i <= n; ++ i) {
    queue.push(read());
  }
  double p = (double) u / v;
  int lost_val = 0;
  for (int i = 1; i <= m; ++ i) {
    int top = queue.top(); queue.pop();
    top += lost_val;
    if (i % t == 0) {
      printf("%d ", top);
    }
    int x = p * top;
    int y = top - x;
    // printf("pushed: (%d, %d)\n", x, y);
    lost_val += q;
    queue.push(x - lost_val);
    queue.push(y - lost_val);
  }
  puts("");
  int rk = 0;
  while (!queue.empty()) {
    if ((++ rk) % t == 0) {
      printf("%d ", queue.top() + lost_val);
    }
    queue.pop();
  }
  puts("");
  return 0;
}