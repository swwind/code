#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[20];

struct Fraction {
  int a, b;
  bool valid = true;
  Fraction(int _a, int _b) {
    if (_b == 0) {
      valid = false;
    } else if (_a == 0) {
      a = 0;
      b = 1;
    } else {
      int g = __gcd(abs(_a), _b);
      a = _a / g;
      b = _b / g;
    }
  }
  Fraction(int _a) {
    a = _a;
    b = 1;
  }
  bool operator<(const Fraction &rhs) const {
    // a/b < c/d
    // a*d < c*b
    return a * rhs.b < rhs.a * b;
  }
  Fraction operator+(const Fraction &rhs) const {
    return Fraction(a * rhs.b + rhs.a * b, b * rhs.b);
  }
  Fraction operator-(const Fraction &rhs) const {
    return Fraction(a * rhs.b - rhs.a * b, b * rhs.b);
  }
  Fraction operator*(const Fraction &rhs) const {
    return Fraction(a * rhs.a, b * rhs.b);
  }
  Fraction operator/(const Fraction &rhs) const {
    return Fraction(a * rhs.b, b * rhs.a);
  }
  Fraction operator-() const { return Fraction(-a, b); }
  bool operator==(const Fraction &rhs) const {
    return a == rhs.a && b == rhs.b;
  }
};

bool frac_unused;
bool frac_used;

int c[20];

void dfs2(int x, Fraction v, bool fraction_used) {
  if (x == n + 1) {
    if (v == Fraction(m)) {
      if (fraction_used) {
        frac_used = true;
      } else {
        frac_unused = true;
      }
    }
    return;
  }

  Fraction u = Fraction(c[x]);
  Fraction res[] = {v / u, v * u, v - u, v + u, u / v, u * v, u - v, u + v};
  for (int i = 0; i < 8; i++) {
    if (res[i].valid) {
      dfs2(x + 1, res[i], fraction_used || res[i].b > 1);
    }
  }
}

void dfs3() {
  // printf("hello\n");
  Fraction cf[] = {Fraction(c[1]), Fraction(c[2]), Fraction(c[3]), Fraction(c[4])};
  Fraction res1[] = {cf[0] / cf[1], cf[0] * cf[1], cf[0] - cf[1], cf[0] + cf[1], cf[1] / cf[0], cf[1] * cf[0], cf[1] - cf[0], cf[1] + cf[0]};
  Fraction res2[] = {cf[2] / cf[3], cf[2] * cf[3], cf[2] - cf[3], cf[2] + cf[3], cf[3] / cf[2], cf[3] * cf[2], cf[3] - cf[2], cf[3] + cf[2]};

  for (size_t i = 0; i < 8; ++ i) {
    for (size_t j = 0; j < 8; ++ j) {
  // printf("world %d %d\n", i, j);
      Fraction u = res1[i];
      Fraction v = res2[j];
      if (!u.valid || !v.valid) {continue;}
      Fraction res[] = {v / u, v * u, v - u, v + u, u / v, u * v, u - v, u + v};
      for (size_t k = 0; k < 8; ++ k) {
        if (!res[k].valid) {continue;}
        if (res[k] == Fraction(m)) {
          if (u.b > 1 || v.b > 1) {
            frac_used = true;
          } else {
            frac_unused = true;
          }
        }
      }
    }
  }
  // printf("fuck\n");
}

bool check() {
  vector<int> b;
  frac_unused = frac_used = false;
  for (int i = 1; i <= n; ++ i) {
    b.push_back(i);
  }
  do {
    for (int i = 1; i <= n; ++ i) {
      c[i] = a[b[i-1]];
    }
    dfs2(2, Fraction(c[1]), false);
    if (n == 4) dfs3();
  } while (next_permutation(b.begin(), b.end()));
  return frac_used && !frac_unused;
}

struct Answer {
  int a[4];
  Answer(int *b) {
    for (int i = 0; i < 4; ++ i) {
      a[i] = b[i];
    }
  }
};
vector<Answer> ans;

void dfs1(int x) {
  // printf("dfs %d\n", x);
  // printf("%d == %d\n", x, n + 1);
  if (x == n + 1) {
    if (check()) {
      ans.push_back(Answer(a+1));
    }
    return;
  }
  // puts("fuck");

  for (int i = max(a[x-1], 1); i <= 13; ++ i) {
    a[x] = i;
    dfs1(x + 1);
  }
}

int main() {
  scanf("%d%d", &n, &m);

  dfs1(1);

  printf("%d\n", ans.size());
  for (size_t i = 0; i < ans.size(); ++ i) {
    for (int j = 0; j < n; ++ j) {
      printf("%d%c", ans[i].a[j], " \n"[j == 3]);
    }
  }
}