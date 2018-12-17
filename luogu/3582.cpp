    #include <bits/stdc++.h>
    #define N 1000020
    #define ll long long
    inline int read(){
      int x=0,f=1;char ch=getchar();
      while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
      while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
      return f?x:-x;
    }
    ll f[N], w[N], head[N], pre[N]; // prpr
    namespace __segment_tree {
      ll mx[N<<2], fl[N<<2];
      void push_down(int x) {
        if (fl[x]) {
          mx[x << 1] += fl[x];
          mx[x<<1|1] += fl[x];
          fl[x << 1] += fl[x];
          fl[x<<1|1] += fl[x];
          fl[x] = 0;
        }
      }
      void push_up(int x) {
        mx[x] = std::max(mx[x << 1], mx[x<<1|1]);
      }
      void update(int x, int l, int r, int L, int R, ll v) {
        if (l == L && r == R) {
          mx[x] += v;
          fl[x] += v;
          return;
        }
        push_down(x);
        int mid = (L + R) >> 1;
        if (r <= mid) update(x << 1, l, r, L, mid, v);
        else if (l > mid) update(x<<1|1, l, r, mid + 1, R, v);
        else update(x << 1, l, mid, L, mid, v), update(x<<1|1, mid + 1, r, mid + 1, R, v);
        push_up(x);
      }
      ll query_max(int x, int l, int r, int L, int R) {
        if (l == L && r == R) return mx[x];
        push_down(x);
        int mid = (L + R) >> 1;
        if (r <= mid) return query_max(x << 1, l, r, L, mid);
        else if (l > mid) return query_max(x<<1|1, l, r, mid + 1, R);
        else return std::max(query_max(x << 1, l, mid, L, mid), query_max(x<<1|1, mid + 1, r, mid + 1, R));
      }
    }
    int main(int argc, char const *argv[]) {
      int n = read(), m = read();
      for (int i = 1; i <= n; ++ i) {
        f[i] = read();
        pre[i] = head[f[i]];
        head[f[i]] = i;
      }
      for (int i = 1; i <= m; ++ i) {
        w[i] = read();
      }
      ll ans = 0;
      for (int i = 1; i <= n; ++ i) {
        __segment_tree::update(1, pre[i] + 1, i, 1, n, w[f[i]]);
        if (pre[i]) {
          __segment_tree::update(1, pre[pre[i]] + 1, pre[i], 1, n, -w[f[i]]);
        }
        ans = std::max(ans, __segment_tree::query_max(1, 1, i, 1, n));
      }
      std::cout << ans << std::endl;
      return 0;
    }