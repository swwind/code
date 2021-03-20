#include<bits/stdc++.h>
using namespace std;
int fuck(int x){
  int ans = 0;
  for (int i = 1; i < x; ++ i) {
    if (x % i == 0) ans += i;
  }
  return ans;
}
int main(){
  int s;cin>>s;
  while(s--){
    int a,b;
    cin>>a>>b;
    puts(fuck(a)==b&&fuck(b)==a?"YES":"NO");
  }
}