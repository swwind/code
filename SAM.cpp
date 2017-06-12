#include <bits/stdc++.h>
#define N 233
class SAM{
public:
	int ch[N][30], fa[N], l[N], p, np, last, cnt, rt, q, nq;
	char s[N], c;
	void extend(int x){
		p = last;
		c = s[l[last=np=++cnt]=x]-'a';
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c] = np;
		if(!p) fa[np] = rt;
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
	SAM(){sam.last = sam.rt = ++cnt;}
}sam;
int main(){}