#include <bits/stdc++.h>
#define N 4018
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int rl[N], mx;
ll ansr[N], ansl[N];
void addAnsR(int l, int r) {
  ansr[l] ++; ansr[r + 1] --;
}
void addAnsL(int l, int r) {
  ansl[l] ++; ansl[r + 1] --;
}
void manacher(char *s, int len) {
  int mxr = -1, pos = 0;
  for (int i = 0; i < len; ++ i) {
    rl[i] = i < mxr ? min(rl[2 * pos - i], mxr - i) : 1;
    while (i - rl[i] >= 0 && i + rl[i] < len && s[i - rl[i]] == s[i + rl[i]])
      rl[i] ++;
    if (i + rl[i] - 1 > mxr) {
      mxr = i + rl[i] - 1;
      pos = i;
    }
    if (i & 1) {
      int k = rl[i] >> 1;
      int id = i + 1 >> 1;
      addAnsR(id, id + k - 1);
      addAnsL(id - k + 1, id);
    } else {
      int k = rl[i] >> 1;
      int id = i >> 1;
      addAnsR(id + 1, id + k);
      addAnsL(id - k + 1, id);
    }
    // printf("%d -> %d\n", i, rl[i]);
  }
}
char str[N], _str[N<<1];
int main(int argc, char const *argv[]) {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  int len = n * 2 + 1;
  for (int i = 1; i <= len; ++ i)
    _str[i] = (i & 1) ? '#' : str[i >> 1];
  // puts(_str + 1);
  manacher(_str + 1, len);
  for (int i = 1; i <= n; ++ i) {
    ansr[i] += ansr[i - 1];
    ansl[i] += ansl[i - 1];
  }
  // for (int i = 1; i <= n; ++ i)
  //   printf("%d\n", ansr[i]);
  for (int i = n - 1; i; -- i) {
    ansl[i] += ansl[i + 1];
  }
  ll ans = 0;
  for (int i = 1; i < n; ++ i) {
    // printf("%d, %d\n", ansr[i], ansl[i + 1]);
    ans += ansr[i] * ansl[i + 1];
  }
  cout << ans << endl;
  return 0;
}