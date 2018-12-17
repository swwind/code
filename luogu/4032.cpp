#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
// 保存煮熟的食物
namespace TreeArray {
  int c[N], n;
  void update(int x, int v) {
    for (; x <= n; x += x & -x) {
      c[x] += v;
    }
  }
  int query(int x) {
    int res = 0;
    for (; x; x ^= x & -x) {
      res += c[x];
    }
    return res;
  }
  void clear() {
    memset(c, 0, sizeof c);
  }
  int upper_bound(int v) {
    int x = 0, sum = 0;
    for (int i = 16; ~i; -- i) {
      int nxt = x + (1 << i);
      if (nxt <= n && sum + c[nxt] <= v) {
        sum += c[x = nxt];
      }
    }
    return x;
  }
}
typedef pair<int, int> prpr;
/**
 * 在锅里的食物
 * first(int): 熟的时间
 * second(int): 食物的种类
 */
priority_queue<prpr, std::vector<prpr>, std::greater<prpr>> raw_food;
/**
 * 还在煮熟的食物
 */
priority_queue<int, std::vector<int>, std::greater<int>> cooked_food[N];
int s[N];
int queryFood(int l, int r) {
  return TreeArray::query(r) - TreeArray::query(l - 1);
}
void loadTime(int t) {
  while (!raw_food.empty() && raw_food.top().first <= t) {
    int id = raw_food.top().second;
    raw_food.pop();
    TreeArray::update(id, 1);
    cooked_food[id].pop();
  }
}
int main(int argc, char const *argv[]) {
  int T = read();
  while (T --) {
    int n = read();
    TreeArray::n = n;
    for (int i = 1; i <= n; ++ i) {
      s[i] = read();
    }
    int q = read();
    while (q --) {
      int t = read(), op = read();
      loadTime(t);
      if (op == 0) {
        int id = read();
        raw_food.push({t + s[id], id});
        cooked_food[id].push(t);
      }
      if (op == 1) {
        int id = TreeArray::upper_bound(0);
        if (id == n) puts("Yazid is angry.");
        else printf("%d\n", id + 1), TreeArray::update(id + 1, -1);
      }
      if (op == 2) {
        int id = read();
        int sum = queryFood(id, id);
        if (sum) puts("Succeeded!"), TreeArray::update(id, -1);
        else if (!cooked_food[id].empty()) printf("%d\n", cooked_food[id].top() + s[id] - t);
        else puts("YJQQQAQ is angry.");
      }
      if (op == 3) {
        int l = read(), r = read();
        printf("%d\n", queryFood(l, r));
      }
    }
    TreeArray::clear();
    for (int i = 1; i <= n; ++ i) {
      while (!cooked_food[i].empty()) {
        cooked_food[i].pop();
      }
    }
    while (!raw_food.empty()) {
      raw_food.pop();
    }
  }
  return 0;
}
