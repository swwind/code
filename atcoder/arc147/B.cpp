#include <bits/stdc++.h>
#define N 405
using namespace std;

int a[N];

struct fuck {
  char type;
  int op;
};

vector<fuck> ans;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  // move every odd number to the end
  for (int i = 1; i <= n; i += 2) {
    if (!(a[i] & 1)) {
      for (int j = i; j - 2 >= 1; j -= 2) {
        swap(a[j - 2], a[j]);
        ans.push_back((fuck) { 'B', j - 2 });
      }
    }
  }

  // move every even number to the end
  for (int i = 2; i <= n; i += 2) {
    if ((a[i] & 1)) {
      for (int j = i; j - 2 >= 1; j -= 2) {
        swap(a[j - 2], a[j]);
        ans.push_back((fuck) { 'B', j - 2 });
      }
    }
  }

  for (int i = 1; i + 1 <= n; i += 2) {
    if (!(a[i] & 1) && (a[i + 1] & 1)) {
      swap(a[i], a[i + 1]);
      ans.push_back((fuck) { 'A', i });
    }
  }

  for (int i = 1; i <= n; i += 2) {
    for (int j = i; j - 2 >= 1; j -= 2) {
      if (a[j - 2] > a[j]) {
        swap(a[j - 2], a[j]);
        ans.push_back((fuck) { 'B', j - 2 });
      }
    }
  }

  for (int i = 2; i <= n; i += 2) {
    for (int j = i; j - 2 >= 1; j -= 2) {
      if (a[j - 2] > a[j]) {
        swap(a[j - 2], a[j]);
        ans.push_back((fuck) { 'B', j - 2 });
      }
    }
  }


  printf("%u\n", ans.size());
  for (auto& x : ans) {
    printf("%c %d\n", x.type, x.op);
  }

  for (int i = 1; i <= n; ++i) {
    assert(a[i] == i);
  }

}

/*
5 4 3 2 1
3 4 5 2 1
3 4 1 2 5
3 4 5 2 1
*/
