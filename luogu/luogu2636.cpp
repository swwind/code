#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char ch[N], tmp[N];
int len;
// char qwe[] = "abcdefghijklmnopqrstuvwxyz";
char qwe[] = "kxvmcnophqrszyijadlegwbuft";
bool bg[N];
int op[1020], a[1020];
string str[1020];
int main(int argc, char const *argv[]) {
  int n = read();
  scanf("%s", ch + 1);
  len = strlen(ch + 1);
  for (int i = 1; i <= len; i++)
    if (ch[i] < 'a')
      bg[i] = 1, ch[i] = tolower(ch[i]);
  for (int i = 1; i <= n; i++) {
    op[i] = read();
    if (op[i] == 1) a[i] = read();
    if (op[i] == 2) cin >> str[i];
  }
  for (int s = n; s; s--) {
    if (op[s] == 1) {
      int l = a[s];
      for (int i = 1, j = 1, k = 1; i <= len; i++, j += l) {
        if (j > len) j = ++ k;
        tmp[j] = ch[i];
      }
      memcpy(ch, tmp, sizeof tmp);
    }
    if (op[s] == 2) {
      int key_len = str[s].length();
      for (int i = 1, j = 1; i <= len; i++, j++) {
        ch[i] = 'a' + (ch[i] - tolower(str[s][j - 1]) + 26) % 26;
        if (j == key_len) j = 0;
      }
    }
    if (op[s] == 3) {
      for (int i = 1; i <= len; i++)
        ch[i] = qwe[ch[i] - 'a'];
    }
  }
  for (int i = 1; i <= len; i++)
    if (bg[i]) putchar(toupper(ch[i]));
    else putchar(ch[i]);
  puts("");
  return 0;
}