#include <cstdio>
#include <algorithm>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

struct student {
  int grade, id;
} stu[N];

bool cmp(const student &a, const student &b) {
  return a.grade == b.grade ? a.id < b.id : a.grade > b.grade;
}

int main() {
  int n = read(), m = read() * 1.5;
  for (int i = 1; i <= n; ++ i) {
    stu[i].id = read();
    stu[i].grade = read();
  }

  sort(stu + 1, stu + n + 1, cmp);
  int fuck = stu[m].grade;
  int tot = 0;
  for (int i = 1; i <= n; ++ i) {
    if (stu[i].grade >= fuck) ++ tot;
  }
  printf("%d %d\n", fuck, tot);
  for (int i = 1; i <= tot; ++ i) {
    printf("%d %d\n", stu[i].id, stu[i].grade);
  }
}
