#include <bits/stdc++.h>
#define N 9600020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

struct node {
  int x, y;
};

map<int, vector<node>> mp;
vector<int> ans;

int ch[N][2], rt = 1, cnt = 1;
int pt[N];
int a[N];

void insert(int x, int p) {
  int now = rt;
  for (int i = 29; ~i; -- i) {
    int v = (x>>i)&1;
    if (!ch[now][v]) {
      ch[now][v] = ++ cnt;
    }
    now = ch[now][v];
    // printf("now = %d\n", now);
  }
  // printf("pt[%d] = %d\n", now, p);
  pt[now] = p;
}

int max_xor(int base) {
  int now = rt;
  for (int i = 29; ~i; -- i) {
    int b = (base>>i)&1;
    if (ch[now][!b]) {
      now = ch[now][!b];
    } else {
      now = ch[now][b];
    }
  }
  return pt[now];
}

int main() {

  int n = read(), k = read();
  if (!k) {
    printf("%d\n", n);
    for (int i = 1; i <= n; ++ i) {
      printf("%d%c", i, " \n"[i == n]);
    }
    return 0;
  }

  int kbit = -1;
  for (int i = 29; ~i; -- i) {
    if ((k >> i) & 1) {
      kbit = i;
      break;
    }
  }
  int full_mask = ((1<<30)-1);
  int k_mask = ((1<<(kbit+1))-1);
  int elon_musk = full_mask ^ k_mask; 
  // printf("kmask = %d\n", k_mask);

  for (int i = 1; i <= n; ++ i) {
    a[i] = read();
    mp[elon_musk&a[i]].push_back((node){a[i],i});
  }
  for (auto pr : mp) {
    vector<node> vec = pr.second;
    // printf("%d %u\n", pr.first, vec.size());
    if (vec.size() == 1) {
      ans.push_back(vec[0].y);
      continue;
    }
    // todo clean
    for (int i = 1; i <= cnt; ++ i) {
      ch[i][0] = ch[i][1] = 0;
      // pt[i] = 0;
    }
    cnt = 1;
    // rt = 1;
    for (node v : vec) {
      // printf("insert %d %d\n", v.x, v.y);
      insert(v.x, v.y);
    }
    for (node v : vec) {
      int g = max_xor(v.x);
      // printf("maxxor(%d) = a[%d] = %d\n", v.x, g, a[g]);
      if ((a[g] ^ v.x) >= k) {
        ans.push_back(v.y);
        ans.push_back(g);
        break;
      }
    }
  }
  if (!ans.size()) return puts("-1")&0;
  printf("%u\n", ans.size());
  for (size_t i = 0; i < ans.size(); ++ i) {
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
  }
}
