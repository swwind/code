#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int MAXN = 1000005;

long long fact[MAXN], invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int total0 = 0, total1 = 0;
    int cnt0_blocks = 0, cnt1_blocks = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            total0++;
            if (i == 0 || s[i - 1] != '0') cnt0_blocks++;
        } else {
            total1++;
            if (i == 0 || s[i - 1] != '1') cnt1_blocks++;
        }
    }

    long long ans0 = (cnt0_blocks > 0) ? nCr(total0 - 1, cnt0_blocks - 1) : 1;
    long long ans1 = (cnt1_blocks > 0) ? nCr(total1 - 1, cnt1_blocks - 1) : 1;

    long long ans = (ans0 * ans1) % MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
