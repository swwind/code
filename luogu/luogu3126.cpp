#include <bits/stdc++.h>
#define N 520
#define mod 1000000007
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char ch[N][N];
ll f[2][N][N];
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++)
    scanf("%s", ch[i] + 1);
  if (ch[1][1] != ch[n][n])
    return puts("0"), 0;
  int now = 1, pre = 0;
  f[now][1][1] = 1;
  for (int s = 2; s <= n; s++) {
    now ^= 1; pre ^= 1;
    memset(f[now], 0, sizeof f[now]);
    for (int i = 1; i <= s; i++) {
      for (int j = 1; j <= s; j++) {
        // 第 s 条副对角线，第 i 个元素。
        //  ///         
        // 111         
        // 22         
        // 第 2n-s 条副对角线，第 j 个元素。
        //             /   
        //            1/   
        //           21/   
        //          321/   
        //         4321    
        if (ch[i][s - i + 1] == ch[n - s + j][n - j + 1]) {
          f[now][i][j] = f[pre][i - 1][j - 1] + f[pre][i - 1][j] + f[pre][i][j - 1] + f[pre][i][j];
          f[now][i][j] = f[now][i][j] % mod;
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + f[now][i][i]) % mod;
  cout << ans << endl;
  return 0;
}