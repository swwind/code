#pragma GCC optimize 2
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
map<int, long long> step;
map<int, int> min_step;
queue<int> q;
int _pow10[15];
// 获取 x 的第 i 位
inline int get_pos(int x, int i) {
  return x / _pow10[i] % 10;
}
// 把 x 的第 i 位变成 z
inline int change_pos(int x, int i, int z) {
  int rem = x % _pow10[i];
  int quo = x / _pow10[i + 1] * 10 + z;
  return quo * _pow10[i] + rem;
}
// 交换 x 的 i 和 j 位
inline int exchange(int x, int i, int j) {
  int res = x;
  res = change_pos(res, i, get_pos(x, j));
  res = change_pos(res, j, get_pos(x, i));
  return res;
}
inline int move_step(int x, int t) {
  if (t == 1) {
    // type 1
    // 8 7 6
    // 5 4 3
    // 2 1 0
    int res = x;
    res = exchange(res, 3, 0);
    res = exchange(res, 1, 0);
    res = exchange(res, 1, 2);
    res = exchange(res, 5, 2);
    res = exchange(res, 5, 8);
    res = exchange(res, 7, 8);
    res = exchange(res, 7, 6);
    return res;
  } else {
    // type 2
    int res = x;
    res = exchange(res, 3, 5);
    res = exchange(res, 4, 5);
    return res;
  }
}
inline int rev_move_step(int x, int t) {

  if (t == 1) {
    // type 1
    // 8 7 6
    // 5 4 3
    // 2 1 0
    int res = x;
    res = exchange(res, 3, 6);
    res = exchange(res, 7, 6);
    res = exchange(res, 7, 8);
    res = exchange(res, 5, 8);
    res = exchange(res, 5, 2);
    res = exchange(res, 1, 2);
    res = exchange(res, 1, 0);
    return res;
  } else {
    // type 2
    int res = x;
    res = exchange(res, 3, 4);
    res = exchange(res, 4, 5);
    return res;
  }
}
inline void print(int x) {
  printf("%d %d %d\n", get_pos(x, 8), get_pos(x, 7), get_pos(x, 6));
  printf("%d %d %d\n", get_pos(x, 5), get_pos(x, 4), get_pos(x, 3));
  printf("%d %d %d\n", get_pos(x, 2), get_pos(x, 1), get_pos(x, 0));
  puts("");
}
int main(int argc, char const *argv[]) {
  int ed = 0;
  _pow10[0] = 1;
  for (int i = 1; i <= 9; ++ i) {
    ed = ed * 10 + read();
    _pow10[i] = _pow10[i - 1] * 10;
  }
  int st = 12345678;
  q.push(st);
  min_step[st] = 0;
  step[st] = 0;
  bool solved = false;
  while (!solved && !q.empty()) {
    int x = q.front(); q.pop();
    for (int t = 0; t < 2; ++ t) {
      int xx = move_step(x, t);
      if (!min_step.count(xx)) {
        min_step[xx] = min_step[x] + 1;
        long long vec = step[x] << 1 | t;
        step[xx] = vec;
        if (xx == ed) {
          solved = true;
        }
        q.push(xx);
      }
    }
  }
  // cout << solved << endl;
  cout << min_step[ed] << endl;
  int _ed = ed;
  print(_ed);
  long long vec = step[ed];
  for (int i = 0; i < min_step[ed]; ++ i) {
    int t = vec >> i & 1;
    _ed = rev_move_step(_ed, t);
    print(_ed);
  }
  return 0;
}