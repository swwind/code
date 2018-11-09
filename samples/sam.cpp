// 后缀自动机
// 玄学领域 x 2

#include <bits/stdc++.h>
#define N 233
class SAM{
public:
	int ch[N][30], fa[N], l[N], p, np, last, cnt, q, nq;
	void extend(int c){
		p = last; l[last=np=++cnt]=l[p]+1;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c] = np;
		if(!p) fa[np] = 1;
		else{
			q = ch[p][c];
			if(l[q] == l[p]+1) fa[np] = q;
			else{
				l[nq=++cnt] = l[p]+1;
				memcpy(ch[nq], ch[q], sizeof ch[p]);
				fa[nq] = fa[q];
				fa[q] = fa[np] = nq;
				for(;ch[p][c]==q;p=fa[p]) ch[p][c] = nq;
			}
		}
	}
	SAM(){last = ++cnt;}
}sam;
int main(){}