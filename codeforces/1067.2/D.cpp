#include <bits/stdc++.h>
#include <cstdio>
#include <utility>

#define N 250

char s[N];
char t[N];
int d[N];

std::vector<std::pair<int, int>> solutions;

std::vector<std::pair<int, int>> solve_from_zero(int x) {
  if (x == 0b0000)
    return {};
  if (x == 0b0001) {
    auto sol = solve_from_zero(0b1111);
    sol.push_back(std::make_pair(0, 2));
    return sol;
  }
  if (x == 0b0010) {
    auto sol = solve_from_zero(0b1110);
    sol.push_back(std::make_pair(0, 1));
    return sol;
  }
  if (x == 0b0011) {
    auto sol = solve_from_zero(0b0000);
    sol.push_back(std::make_pair(2, 3));
    return sol;
  }
  if (x == 0b0100) {
    auto sol = solve_from_zero(0b0111);
    sol.push_back(std::make_pair(2, 3));
    return sol;
  }
  if (x == 0b0101) {
    auto sol = solve_from_zero(0b0010);
    sol.push_back(std::make_pair(1, 3));
    return sol;
  }
  if (x == 0b0110) {
    auto sol = solve_from_zero(0b0000);
    sol.push_back(std::make_pair(1, 2));
    return sol;
  }
  if (x == 0b0111) {
    auto sol = solve_from_zero(0b0000);
    sol.push_back(std::make_pair(1, 3));
    return sol;
  }

  if (x == 0b1000) {
    auto sol = solve_from_zero(0b1111);
    sol.push_back(std::make_pair(1, 3));
    return sol;
  }
  if (x == 0b1001) {
    auto sol = solve_from_zero(0b1111);
    sol.push_back(std::make_pair(1, 2));
    return sol;
  }
  if (x == 0b1010) {
    auto sol = solve_from_zero(0b0100);
    sol.push_back(std::make_pair(0, 2));
    return sol;
  }
  if (x == 0b1011) {
    auto sol = solve_from_zero(0b1000);
    sol.push_back(std::make_pair(2, 3));
    return sol;
  }
  if (x == 0b1100) {
    auto sol = solve_from_zero(0b0000);
    sol.push_back(std::make_pair(0, 1));
    return sol;
  }
  if (x == 0b1101) {
    auto sol = solve_from_zero(0b0001);
    sol.push_back(std::make_pair(0, 1));
    return sol;
  }
  if (x == 0b1110) {
    auto sol = solve_from_zero(0b0000);
    sol.push_back(std::make_pair(0, 2));
    return sol;
  }
  if (x == 0b1111) {
    auto sol = solve_from_zero(0b0000);
    sol.push_back(std::make_pair(0, 3));
    return sol;
  }

  return {};
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;

    solutions.clear();

    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    // for (int i = 1; i <= n; ++i)
    //   d[i] = s[i] == t[i];

    for (int i = 1; i + 4 <= n; ++i) {
      if (s[i] == t[i])
        continue;

      if (s[i] == s[i + 1]) {
        solutions.push_back(std::make_pair(i, i + 1));
        s[i] ^= 1;
        s[i + 1] ^= 1;
        continue;
      }

      if (s[i] == s[i + 2]) {
        solutions.push_back(std::make_pair(i, i + 2));
        s[i] ^= 1;
        s[i + 1] ^= 1;
        s[i + 2] ^= 1;
        continue;
      }

      solutions.push_back(std::make_pair(i + 1, i + 2));
      solutions.push_back(std::make_pair(i, i + 1));
      s[i] ^= 1;
      s[i + 2] ^= 1;
    }

    // dfs the remaining
    int base = n - 3;

    int a = s[n - 3] - '0';
    int b = s[n - 2] - '0';
    int c = s[n - 1] - '0';
    int d = s[n] - '0';
    auto sol1 = solve_from_zero(a << 3 | b << 2 | c << 1 | d);

    a = t[n - 3] - '0';
    b = t[n - 2] - '0';
    c = t[n - 1] - '0';
    d = t[n] - '0';
    auto sol2 = solve_from_zero(a << 3 | b << 2 | c << 1 | d);

    printf("%lu\n", solutions.size() + sol1.size() + sol2.size());
    for (auto pr : solutions) {
      printf("%d %d\n", pr.first, pr.second);
    }

    for (int i = sol1.size() - 1; i >= 0; --i) {
      printf("%d %d\n", base + sol1[i].first, base + sol1[i].second);
    }
    for (int i = 0; i < sol2.size(); ++i) {
      printf("%d %d\n", base + sol2[i].first, base + sol2[i].second);
    }
  }
}