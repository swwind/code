#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3e5 + 7; // 2^21

int n, a, b, p, q;
int jc[N], inv[N], G[N];

namespace NTT {
    int limit;
    vector<int> A, B, rev;
    inline int add(int x, int y) { return x += y, x >= MOD ? x - MOD : x; }
    inline int mul(int x, int y) { return 1ll * x * y % MOD; }
    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1, x = mul(x, x)) if (y & 1) res = mul(res, x);
        return res;
    }
    void init() {
        int ed = n * 2, bit = -1;
        for (limit = 1; limit <= ed; limit <<= 1) ++bit;
        A.resize(limit); B.resize(limit); rev.resize(limit);
        for (int i = 0; i < limit; ++i)    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit);
    }
    void ntt(vector<int>& P, int op) {
        for (int i = 0; i < limit; ++i) {
            if (i < rev[i])swap(P[i], P[rev[i]]);
        }
        for (int mid = 1; mid < limit; mid <<= 1) {
            int euler = qpow(3, (MOD - 1) / (mid << 1));
            if (op < 0)    euler = qpow(euler, MOD - 2);
            for (int i = 0, pos = mid << 1; i < limit; i += pos) {
                int wk = 1;
                for (int j = 0; j < mid; ++j, wk = mul(wk, euler)) {
                    int x = P[i + j], y = mul(wk, P[i + j + mid]);
                    P[i + j] = add(x, y), P[i + j + mid] = add(x, MOD - y);
                }
            }
        }
        if (op > 0)    return;
        int inv = qpow(limit, MOD - 2);
        for (int i = 0; i < limit; ++i)    P[i] = mul(P[i], inv);
    }
    void work() {
        for (int i = 0; i <= n; ++i) A[i] = i & 1 ? MOD - inv[i] : inv[i];
        for (int i = 0; i <= n; ++i) B[i] = mul(G[i], inv[i]);
        for (int i = 0; i <= n; ++i) printf("%d%c", A[i], " \n"[i==n]);
        for (int i = 0; i <= n; ++i) printf("%d%c", B[i], " \n"[i==n]);
        ntt(A, 1), ntt(B, 1);
        for (int i = 0; i < limit; ++i)    A[i] = mul(A[i], B[i]);
        ntt(A, -1);
    }
}using namespace NTT;


void init(int n) {
    jc[0] = 1;
    for (int i = 1; i <= n; ++i) {
        jc[i] = mul(jc[i - 1], i);
    }
    inv[n] = qpow(jc[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }
}
int C(int n, int m) {
    return 1ll * jc[n] * inv[n - m] % MOD * inv[m] % MOD;
}
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int solve() {
    n = read(), a = read(), b = read();

    init(n);
    p = mul(a, qpow(b, MOD - 2)); // 没打中概率
    q = (1 - p + MOD) % MOD; // 打中概率

    int tmp_inv = mul(inv[n - 1], jc[n - 2]);
    for (int i = 0; i <= n; ++i) {
        G[i] = mul(qpow(add(q, mul(mul(p, i - 1), tmp_inv)), i), qpow(add(q, mul(mul(p, i), tmp_inv)), n - i));
    }
    init();
    work();
    for (int i = n; i >= 0; --i) {
        printf("%lld\n", 1ll * C(n, i) * A[i] % MOD * jc[i] % MOD);
    }

    return 1;
}
int main() {
  solve();
}