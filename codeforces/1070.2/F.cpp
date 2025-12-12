#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;
const int MAXW = 8; // Max omega is 6 for 200000

int omega[MAXN];
int mu[MAXN];
int min_prime[MAXN];
int cnt[MAXN][MAXW]; // cnt[divisor][omega_val]
long long cost[MAXN];
long long powers[20];
vector<int> divisors[MAXN];

// Precompute Mobius function, omega function, and smallest prime factor
void sieve() {
  fill(min_prime, min_prime + MAXN, 0);
  mu[1] = 1;
  omega[1] = 0;
  vector<int> primes;
  for (int i = 2; i < MAXN; ++i) {
    if (min_prime[i] == 0) {
      min_prime[i] = i;
      primes.push_back(i);
      omega[i] = 1;
      mu[i] = -1;
    }
    for (int p : primes) {
      if (p > min_prime[i] || (long long)i * p >= MAXN)
        break;
      int m = i * p;
      min_prime[m] = p;
      if (min_prime[i] == p) {
        omega[m] = omega[i];
        mu[m] = 0;
      } else {
        omega[m] = omega[i] + 1;
        mu[m] = -mu[i];
      }
    }
  }
}

// Precompute divisors for all numbers up to MAXN
void precompute_divisors() {
  for (int i = 1; i < MAXN; ++i) {
    for (int j = i; j < MAXN; j += i) {
      divisors[j].push_back(i);
    }
  }
}

long long power(long long base, long long exp) {
  long long res = 1;
  base %= MOD;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }
  return res;
}

void solve() {
  int n;
  long long k;
  if (!(cin >> n >> k))
    return;

  vector<int> a(n);
  int max_val = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > max_val)
      max_val = a[i];
  }

  // Clear cnt array for relevant range
  for (int i = 1; i <= max_val; ++i) {
    for (int w = 0; w < MAXW; ++w)
      cnt[i][w] = 0;
  }

  // Populate cnt
  for (int x : a) {
    int w = omega[x];
    for (int d : divisors[x]) {
      cnt[d][w]++;
    }
  }

  // Precompute powers v^k for v in [0..14]
  for (int i = 0; i < 20; ++i)
    powers[i] = power(i, k);

  long long total_ans = 0;

  // Iterate over possible values of W = omega(a_i) + omega(a_j)
  // Max omega is 6, so max W is 12. Loop slightly higher for safety.
  for (int W = 0; W <= 13; ++W) {
    // Calculate Cost[T] = sum_{g|T} mu(T/g) * (W - omega(g))^k
    // We compute this using a sieve-like approach over multiples
    for (int i = 1; i <= max_val; ++i)
      cost[i] = 0;

    for (int g = 1; g <= max_val; ++g) {
      if (W < omega[g])
        continue;
      long long val = powers[W - omega[g]];

      // Distribute val to all T that are multiples of g
      for (int T = g; T <= max_val; T += g) {
        // We are adding mu(T/g) * val
        // Check mu(T/g)
        int m_val = mu[T / g];
        if (m_val == 0)
          continue;

        if (m_val == 1) {
          cost[T] = (cost[T] + val);
          if (cost[T] >= MOD)
            cost[T] -= MOD;
        } else {
          cost[T] = (cost[T] - val);
          if (cost[T] < 0)
            cost[T] += MOD;
        }
      }
    }

    // Accumulate answer for pairs (w1, w2) summing to W
    for (int w1 = 0; w1 <= 6; ++w1) {
      int w2 = W - w1;
      if (w2 < w1 || w2 > 6)
        continue;

      for (int T = 1; T <= max_val; ++T) {
        if (cost[T] == 0)
          continue;

        long long c1 = cnt[T][w1];
        long long c2 = cnt[T][w2];
        if (c1 == 0 || c2 == 0)
          continue;

        long long pairs;
        if (w1 == w2) {
          pairs = c1 * (c1 - 1) / 2;
        } else {
          pairs = c1 * c2;
        }
        pairs %= MOD;

        total_ans = (total_ans + pairs * cost[T]) % MOD;
      }
    }
  }

  cout << total_ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  precompute_divisors();
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}