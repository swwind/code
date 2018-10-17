#include <bits/stdc++.h>
#include <ctime>
#define ll long long
#define N 500050
using namespace std;
int n, m, x, root, tot, in;
char ch;
struct node{
	int key, val, l, r, size, aux, add;
}tr[N];
int getRand(){
	return (rand()<<10)+(rand()<<2);
}
void Push_Up(int id){
	tr[id].size = tr[tr[id].l].size
				+ tr[tr[id].r].size
				+ tr[id].val;
}
void Push_Down(int id){
	if(!tr[id].add) return;
	tr[tr[id].l].add += tr[id].add;
	tr[tr[id].r].add += tr[id].add;
	tr[tr[id].l].key += tr[id].add;
	tr[tr[id].r].key += tr[id].add;
	tr[id].add = 0;
}
void Zig(int &id){
	int mmp = tr[id].l;
	tr[id].l = tr[mmp].r;
	tr[mmp].r = id;
	Push_Up(id);
	Push_Up(mmp);
	id = mmp;
}
void Zag(int &id){
	int mmp = tr[id].r;
	tr[id].r = tr[mmp].l;
	tr[mmp].l = id;
	Push_Up(id);
	Push_Up(mmp);
	id = mmp;
}
void Insert(int &id, int v){
	if(!id){
		id = ++tot;
		tr[id].key = v;
		tr[id].l = tr[id].r = tr[id].add = 0;
		tr[id].size = tr[id].val = 1;
		tr[id].aux = getRand();
		return;
	}
	Push_Down(id);
	if(v == tr[id].key){
		tr[id].val++;
		tr[id].size++;
		return;
	}
	else if(v < tr[id].key){
		Insert(tr[id].l, v);
		tr[id].size++;
		if(tr[id].aux > tr[tr[id].l].aux)
			Zig(id);
		return;
	}
	else{
		Insert(tr[id].r, v);
		tr[id].size++;
		if(tr[id].aux > tr[tr[id].r].aux)
			Zag(id);
		return;
	}
}
void Find(int &id){
	if(!id) return;
	Push_Down(id);
	if(tr[id].key < m){
		id = tr[id].r;
		Find(id);
		return;
	}
	else{
		Find(tr[id].l);
		Push_Up(id);
		return;
	}
}
int Kth(int &id, int v){
	if(!id) return 0;
	Push_Down(id);
	if(v > tr[tr[id].r].size &&
		v <= tr[tr[id].r].size + tr[id].val)
		return tr[id].key;
	if(v <= tr[tr[id].r].size)
		return Kth(tr[id].r, v);
	if(v > tr[tr[id].r].size + tr[id].val)
		return Kth(tr[id].l,
			v - tr[tr[id].r].size - tr[id].val);
}
int main(){
	srand(1);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		do ch = getchar(); while(ch<'A'||ch>'Z');
		scanf("%d", &x);
		switch(ch){
		case 'I':
			if(x >= m)Insert(root, x),in++;break;
		case 'A':
			tr[root].key+=x;tr[root].add+=x;break;
		case 'S':
			tr[root].key-=x;tr[root].add-=x;Find(root);break;
		case 'F':
			if(x > tr[root].size)puts("-1");
			else printf("%d\n", Kth(root, x));break;
		}
	}
	printf("%d\n", in-tr[root].size);
	return 0;
}

