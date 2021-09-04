#include <bits/stdc++.h>
#define N 100020

using namespace std;

int mx[N<<2], val[N<<2], lazy[N<<2];

void pushdown(int x, int l, int r) {
	if (lazy[x]) {
    int mid = (l + r) >> 1;
		lazy[x<<1] += lazy[x];
		lazy[x<<1|1] += lazy[x];
		mx[x<<1] += lazy[x];
		mx[x<<1|1] += lazy[x];
		val[x<<1] += lazy[x] * (mid - l + 1);
		val[x<<1|1] += lazy[x] * (r - mid);
		lazy[x] = 0;
	}
}

// 区间加
void update(int x, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		mx[x] += v;
		val[x] += v * (r - l + 1);
		lazy[x] += v;
		return;
	}
	pushdown(x, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) update(x<<1, l, mid, L, R, v);
	if (R > mid) update(x<<1|1, mid+1, r, L, R, v);
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
  val[x] = val[x<<1] + val[x<<1|1];
}

// 询问区间最大值
int query_max(int x, int l, int r, int L, int R) {
  if (l > R || r < L) return 0;
  if (l >= L && r <= R) return mx[x];
  pushdown(x, l, r);
  int mid = (l + r) >> 1;
  return max(query_max(x << 1, l, mid, L, R), query_max(x << 1 | 1, mid + 1, r, L, R));
}

// 询问区间和
int query_sum(int x, int l, int r, int L, int R) {
  if (l > R || r < L) return 0;
  if (l >= L && r <= R) return val[x];
  pushdown(x, l, r);
  int mid = (l + r) >> 1;
  return query_sum(x << 1, l, mid, L, R) + query_sum(x << 1 | 1, mid + 1, r, L, R);
}

int a[N], n, q;

// 输入两个数字 n, q
// 输入长度为 n 的数组 a
// 接下来有 q 次操作，每次操作的类型为 t
// 如果 t 为 1，则读入参数 L, R, v, 并将区间 [L, R] 中的所有元素加上 v
// 如果 t 为 2，则读入参数 L, R, 输出区间 [L, R] 中的最大值
// 如果 t 为 3，则读入参数 L, R, 输出区间 [L, R] 中的和
