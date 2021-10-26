#include <bits/stdc++.h>
#define N 3000020
using namespace std;

bool a[30], b[30];
void split_number(bool *a, int x) {
  for (int i = 0; i < 30; ++ i) {
    a[i] = (x >> (29 - i)) & 1;
  }
}

int ch[2][N], point = 1;
int sz[N];
void insert_number(bool *a) {
  int now = 1;
  for (int i = 0; i < 30; ++ i) {
    if (!ch[a[i]][now]) {
      ch[a[i]][now] = ++ point;
    }
    now = ch[a[i]][now];
  }
  sz[now] ++;
  // printf("++ %d\n", now);
}

void calc_size(int x) {
  if (ch[0][x]) {
    calc_size(ch[0][x]);
    sz[x] += sz[ch[0][x]];
  }
  if (ch[1][x]) {
    calc_size(ch[1][x]);
    sz[x] += sz[ch[1][x]];
  }
}

vector<int> kth[N];
void calc_kth(int x, int bit = 30) {
  if (bit == 0) {
    kth[x].push_back(0);
    return;
  }
  int ls = ch[0][x], lsz = sz[ls];
  int rs = ch[1][x], rsz = sz[rs];

  if (ls) calc_kth(ls, bit - 1);
  if (rs) calc_kth(rs, bit - 1);

  if (!ls || !rs) {
    int son = ls + rs;
    for (int i = 0; i < sz[x]; ++ i) {
      kth[x].push_back(kth[son][i]);
    }
  }

  if (ls && rs) {
    for (int i = 0; i < min(lsz, rsz); ++ i) {
      kth[x].push_back(min(kth[ls][i], kth[rs][i]));
    }
    int modo = lsz > rsz ? ls : rs;
    for (int i = min(lsz, rsz); i < max(lsz, rsz); ++ i) {
      kth[x].push_back(kth[modo][i]);
    }
    for (int i = max(lsz, rsz); i < lsz + rsz; ++ i) {
      kth[x].push_back((1 << (bit - 1)) + min(
        kth[ls][i - rsz],
        kth[rs][i - lsz]
      ));
    }
  }
  // printf("for point: %d\n", x);
  // printf("ls => %d\n", ls);
  // printf("rs => %d\n", rs);
  for (int i = 0; i < sz[x]; ++ i) {
    // printf("==> %d\n", kth[x][i]);
  }
  // printf("%d == %u\n", sz[x], kth[x].size());
}

int find_answer(bool *a, bool *b, int k) {
  int now_i = 0, now = 1, ans = 0;
  while (now_i < 30 && a[now_i] == b[now_i]) {
    // printf("%d, (%d)=(%d), k = %d\n", now_i, sz[ch[0][now]], sz[ch[1][now]], k);
    int chs = a[now_i];
    int ls = ch[0][now];
    int rs = ch[1][now];

    if (chs) swap(ls, rs);
    if (k < sz[ls]) now = ls;
    else now = rs, k -= sz[ls], ans |= (1 << (29 - now_i));

    ++ now_i;
  }
  int limit_l = true;
  int limit_r = true;
  while (now_i < 30) {

    // printf("%d, %d - %d, k = %d\n", now_i, limit_l, limit_r, k);
    // printf("lsz = %d, rsz = %d\n", sz[ch[0][now]], sz[ch[1][now]]);

    assert(k < sz[now]);

    if (!limit_l && !limit_r) {
      // printf("kth[%d][%d] = %d\n", now, k, kth[now][k]);
      // printf("return %d | %d\n", ans, kth[now][k]);
      return ans | kth[now][k];
    }

    int can_chs_l = !(limit_l && a[now_i] == 1);
    int can_chs_r = !(limit_r && b[now_i] == 0);

    assert(can_chs_l || can_chs_r);
    int chs = -1;
    int ls = ch[0][now];
    int rs = ch[1][now];

    if (!can_chs_l || !can_chs_r) {
      chs = can_chs_l ? 0 : 1;
    }

    if (can_chs_l && can_chs_r) {
      // if choose 0
      int lv = k < sz[ls] ? kth[ls][k] : ((1 << (29 - now_i)) + kth[rs][k - sz[ls]]);
      int rv = k < sz[rs] ? kth[rs][k] : ((1 << (29 - now_i)) + kth[ls][k - sz[rs]]);

      // if (rv < lv) chs = 1; else chs = 0;
      if (lv < rv) chs = 0; else chs = 1;
    }

    if (chs) swap(ls, rs);
    if (k < sz[ls]) now = ls;
    else now = rs, k -= sz[ls], ans |= (1 << (29 - now_i));

    if (limit_l && a[now_i] == 0 && chs == 1) limit_l = 0;
    if (limit_r && b[now_i] == 1 && chs == 0) limit_r = 0;

    // printf("choose %d, lb = %d, rb = %d\n", chs, limit_l, limit_r);

    ++ now_i;
  }

  return ans;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++ i) {
    int x;
    scanf("%d", &x);
    split_number(a, x);
    insert_number(a);
  }
  calc_size(1);
  calc_kth(1);

  while (q --) {
    int L, R, k;
    scanf("%d%d%d", &L, &R, &k);

    split_number(a, L);
    split_number(b, R);

    int ans = find_answer(a, b, k - 1);
    printf("%d\n", ans);
  }
}