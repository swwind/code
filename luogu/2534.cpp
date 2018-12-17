#include <bits/stdc++.h>
using namespace std;
struct node{
  int id, val;
  bool operator < (const node &b) const {
    return val < b.val;
  }
}a[60];
int n, pos[60], ans = 1<<30;
void pr(){for(int i = 1; i <= n; i++) printf("%d ", pos[i]);puts("");}
int check(){
  for(int i = 1; i <= n; i++) if(pos[i]!=i)return 0;
  return 1;
}
int get(){
  int sum = 0;
  for(int i = 2; i <= n; i++)
    sum+=abs(pos[i]-pos[i-1])!=1;
  return sum;
}
void rev(int l, int r){
  while(l < r) swap(pos[l++], pos[r--]);
}
void dfs(int dep){
  if(check()) {
    ans = min(ans, dep);
    return;
  }
  if(dep+get()>ans) return;
  for(int i = 2; i <= n; i++){
    rev(1, i);
    dfs(dep+1);
    rev(1, i);
  }
}
int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[a[i].id=i].val);
  sort(a+1, a+n+1);
  for(int i = 1; i <= n; i++) pos[a[i].id] = i;
  ans = n<<1|1;
  dfs(1);
  printf("%d\n", ans-1);
  return 0;
}