#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
typedef pair<ll, ll> pairs;

inline ll calc(ll x) {
  switch (x % 4) {
    case 0: return 0;
    case 1: return x + x - 1;
    case 2: return 2;
    case 3: return x + x + 1;
  }
  return 19260817;
}
inline ll calc(ll l, ll r) {
  return calc(l) ^ calc(r);
}

multiset<pairs> st;
deque<multiset<pairs>::iterator> rub;
ll now;

void update_left(multiset<pairs>::iterator x) {
  if (x != st.begin()) {
    ll u = (ll)x->first * x->first;
    --x;
    now ^= u - ((ll)x->second * x->second);
  }
}

void update_right(multiset<pairs>::iterator x) {
  if (x != --st.end()) {
    ll u = (ll)x->second * x->second;
    ++x;
    now ^= ((ll)x->first * x->first) - u;
  }
}

void insert(ll l, ll r) {
  pairs x = make_pair(l, r);
  auto t = st.lower_bound(x), u = t;
  while (true) {
    if (u == st.begin())
      break;
    --u;
    if (x.first - 1 <= u->second)
      rub.push_front(u);
    else
      break;
  }
  u = t;
  while (true) {
    if (u == st.end())
      break;
    if (x.second + 1 >= u->first)
      rub.push_back(u);
    else
      break;
    ++u;
  }
  for (auto u : rub) {
    if (u->first < x.first)
      x.first = u->first;
    if (u->second > x.second)
      x.second = u->second;
    update_left(u);
    now ^= calc(u -> first, u -> second);
  }
  if (rub.size())
    update_right(*--rub.end());
  else {
    auto t = st.lower_bound(x);
    if (t != st.end())
      update_left(t);
  }
  for (auto u : rub)
    st.erase(u);
  rub.clear();
  st.insert(x);
  update_left(st.find(x));
  update_right(st.find(x));
  now ^= calc(x.second) ^ calc(x.first);
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  ll n = read();
  while (n --) {
    ll op = read();
    if (op == 1) {
      ll l = read(), r = read();
      insert(l, r);
    } else {
      printf("%d\n", now);
    }
  }

  return 0;
}