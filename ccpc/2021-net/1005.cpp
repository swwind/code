#include <bits/stdc++.h>
#define N 100020

using namespace std;

inline long long read(){
	long long x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

struct Fuck {
  long long value;
  int id;
  friend bool operator < (const Fuck &a, const Fuck &b) {
    return a.value == b.value ? a.id > b.id : a.value < b.value;
  }
};

map<long long, vector<Fuck>> mp;
map<long long, int> mmp;

long long a[N];

int main() {
  int T = read();
  while (T --) {
    int n = read(), m = read();
    long long delta = 0;
    for (int i = 1; i <= n; ++ i) {
      a[i] = read();
      delta += a[i];
    }
    if (delta == 0) {
      mmp.clear();
      long long sum = 0;
      mmp[sum] = 0;
      for (int i = 1; i <= n; ++ i) {
        sum += a[i];
        map<long long, int>::iterator it = mmp.find(sum);
        if (it == mmp.end()) {
          mmp[sum] = i;
        }
      }
      for (int i = 1; i <= m; ++ i) {
        long long x = read();
        map<long long, int>::iterator it = mmp.find(x);
        if (it == mmp.end()) {
          puts("-1");
        } else {
          printf("%d\n", it->second);
        }
      }
    } else {
      int global_sign = 1;
      if (delta < 0) {
        delta = - delta;
        global_sign = -1;
      }
      mp.clear();
      mp.insert({0, {(Fuck){0,0}}});
      long long sum = 0;
      for (int i = 1; i <= n; ++ i) {
        sum += global_sign * a[i];
        long long md = (sum % delta + delta) % delta;
        map<long long, vector<Fuck>>::iterator it = mp.find(md);
        Fuck fuck = {sum, i};
        if (it == mp.end()) {
          mp.insert({md, {fuck}});
        } else {
          it->second.push_back(fuck);
        }
      }
      for (map<long long, vector<Fuck>>::iterator it = mp.begin(); it != mp.end(); ++ it) {
        sort(it->second.begin(), it->second.end());
      }
      for (int i = 1; i <= m; ++ i) {
        long long x = read() * global_sign;
        long long md = (x % delta + delta) % delta;
        map<long long, vector<Fuck>>::iterator it = mp.find(md);
        if (it == mp.end()) {
          puts("-1");
        } else {
          vector<Fuck>::iterator res = upper_bound(it->second.begin(), it->second.end(), (Fuck) { x, 0 });
          if (res == it->second.begin()) {
            puts("-1");
          } else {
            -- res;
            printf("%lld\n", (x - res->value) / delta * n + res->id);
          }
        }
      }
    }
  }
}
