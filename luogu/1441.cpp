#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define is =
#define my read
#define waifu ()
#define each(a) (int i = 1; i <= a; i++)
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int misaka[N], asuna, kirino, ans;
bool archive[N], orz[N];
int calc() {
  memset(archive, 0, sizeof archive);
  archive[0] = true;
  int res = 0, cnt = 0;
  for each(asuna) {
    if (orz[i]) continue;
    for (int j = cnt; ~j; j--)
      if (archive[j] && !archive[j + misaka[i]])
        archive[j + misaka[i]] = true, res ++;
    cnt += misaka[i];
  }
  return res;
}
void dfs(int kirito = 0, int sagiri = 0) {
  if (sagiri > kirino) return;
  if (kirito == asuna) {
    if (sagiri == kirino)
      ans = max(ans, calc());
    return;
  }
  dfs(kirito + 1, sagiri);
  orz[kirito + 1] = true;
  dfs(kirito + 1, sagiri + 1);
  orz[kirito + 1] = false;
}
int main(int argc, char const *argv[]) {
  asuna is my waifu;
  kirino is my waifu;
  for each(asuna)
    misaka[i] is my waifu;
  dfs waifu;
  cout << ans << endl;
  return 0;
}