#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

// splay

void build(int x, int l, int r);
void rotate(int x);
void splay(int x);
void access(int x);
void split(int l, int r);

void insert(int x);
void deletes(int x);
int ask_rank(int x);
int ask_by_rank(int rk);
int pre(int x);
int nxt(int x);

int main(int argc, char const *argv[]) {
  
  return 0;
}