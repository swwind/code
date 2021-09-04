#include <bits/stdc++.h>
using namespace std;

struct Box {
  int a[30];
  int b[30];
  int t = 0;

  Box() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
  }
  void from_string(string s) {
    assert(s.length() == 26);
    for (int j = 0; j < 26; j++) {
      int i = s[j] - 'A';
      a[i] = (j-i+26)%26;
      b[j] = (i-j+26)%26;
    }
  }
  void from_patch(vector<string> str) {
    for (string s : str) {
      int i = s[0] - 'A';
      int j = s[1] - 'A';
      b[i] = a[i] = (j-i+26)%26;
      b[j] = a[j] = (i-j+26)%26;
    }
  }
  
  int roll() {
    t = (t + 1) % 26;
    return t;
  }

  int encrypt(int x) {
    // printf("[%c -> %c]\n", x + 'A', (x+a[(x+t)%26])%26 + 'A');
    return (x+a[(x+t)%26])%26;
  }
  int decrypt(int x) {
    // printf("[%c -> %c]\n", x + 'A', (x+b[(x+t)%26])%26 + 'A');
    return (x+b[(x+t)%26])%26;
  }
} d[55];

int main() {
  int T;
  cin >> T;
  while (T --) {
    int p;
    cin >> p;

    vector<string> ps;
    for (int i = 0; i < p; i++) {
      string s;
      cin >> s;
      ps.push_back(s);
    }
    Box patch = Box();
    patch.from_patch(ps);

    int D;
    cin >> D;
    for (int i = 0; i < D; i++) {
      string s;
      cin >> s;
      d[i] = Box();
      d[i].from_string(s);
    }

    for (int i = 0; i < D; i++) {
      int x;
      cin >> x;
      while (x --) {
        d[i].roll();
      }
    }

    // for (int i = 0; i < 26; ++ i) {
    //   printf("d[1].a[%d] = %d\n", i, d[1].a[i]);
    // }

    string s;
    cin >> s;
    Box ref = Box();
    ref.from_string(s);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
      string s;
      cin >> s;
      for (char c : s) {

        for (int j = 0; j < D; j++) {
          if (d[j].roll()) {
            break;
          }
        }

        int x = c - 'A';
        x = patch.encrypt(x);
        for (int j = 0; j < D; j++) {
          x = d[j].encrypt(x);
        }
        x = ref.encrypt(x);
        for (int j = D - 1; j >= 0; j--) {
          x = d[j].decrypt(x);
        }
        // printf("patch.de(0) = %d\n", patch.decrypt(0));
        x = patch.decrypt(x);
        cout << (char)(x + 'A');
      }
      cout << '\n';
    }
  }
}