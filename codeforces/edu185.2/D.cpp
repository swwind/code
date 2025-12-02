#include <bits/stdc++.h>
#include <cstdio>

char s[300030];

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);

    int base = 0, question = 0;
    int q_ivx = 0, q_vx = 0, q_i = 0;
    int q_slot = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == 'I') {
        if (s[i + 1] == 'V' || s[i + 1] == 'X')
          base -= 1;
        else
          base += 1;
      }
      if (s[i] == 'V')
        base += 5;
      if (s[i] == 'X')
        base += 10;

      if (s[i] == '?') {
        question += 1;
        if (s[i - 1] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
          q_ivx += 1;
          s[i] = '#';
        } else if (s[i - 1] == 'I') {
          q_vx += 1;
          s[i] = '#';
        } else if (s[i + 1] == 'V' || s[i + 1] == 'X') {
          q_i += 1;
          s[i] = '#';
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (s[i] == '?' && s[i + 1] == '?') {
        q_slot += 1;
        i += 1;
      }
    }

    while (q--) {
      int cx, cv, ci;
      scanf("%d%d%d", &cx, &cv, &ci);

      int m = question;
      int ans = base;
      int choose_i = std::min(ci, question);
      ans += choose_i;
      int choose_v = std::min(cv, question - choose_i);
      ans += choose_v * 5;
      int choose_x = std::min(cx, question - choose_i - choose_v);
      ans += choose_x * 10;

      int choose_qvx = std::min(choose_v + choose_x, q_vx);
      int choose_qi = std::min(choose_i, q_i);
      int choose_qivx =
          std::min(choose_v + choose_x - choose_qvx + choose_i - q_i, q_ivx);
      ans -= (choose_qvx + choose_qi + choose_qivx) * 2;

      int remain_vx = choose_v + choose_x - choose_qvx;
      int remain_i = choose_i - choose_qi;

      int mx = std::max(remain_vx, remain_i);
      int mn = std::min(remain_vx, remain_i);

      int part_mx = std::min(mx - mn, choose_qivx);
      mx -= part_mx;

      int remain = choose_qivx - part_mx;
      mx -= remain - remain / 2;
      mn -= remain / 2;

      int pairs = std::min(mx, mn);
      int choose_slot = std::min(pairs, q_slot);
      // printf(">> %d %d\n", choose_qivx, choose_slot);
      ans -= choose_slot * 2;

      printf("%d\n", ans);
    }
  }
}