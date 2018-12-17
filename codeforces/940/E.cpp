#include <bits/stdc++.h>
#define N 600020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q1;
priority_queue <ll, vector<ll>, greater<ll>> q2;
ll a[N], sum, n, f[N], k;
int main(int argc, char const *argv[]) {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    sum += a[i] = read();
  f[0] = sum;
  q2.push(sum);
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1];
    q1.push({a[i], i});
    if (k <= i) {
      while (q1.top().second <= i - k)
        q1.pop();
      q2.push(f[i - k] - q1.top().first);
      f[i] = min(f[i], q2.top());
    }
  }
  cout << f[n] << endl;
}
