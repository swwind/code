#include <bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define ll long long
#define N 2100000
using namespace std;
int n, ls[N], rs[N], pre[N], rev[N], size[N], s[N];
int tot, cnt, pos, root, x;
char key[N], str[N];
int maxs(int a, int b){
	if(b < 0) return a;
	return b;
}
int New_Node(int fa, char val){
	int id;
	if(cnt) id = s[cnt--];
	else id = ++tot;
	rs[id] = ls[id] = 0;
	pre[id] = fa;
	rev[id] = 0;
	key[id] = val;
	size[id] = 1;
	return id;
}
void Update_Rev(int id){
	if(!id) return;
	swap(ls[id], rs[id]);
	rev[id] ^= 1;
}
void Push_Up(int id){
	size[id] = size[ls[id]] + size[rs[id]] + 1;
}
void Push_Down(int id){
	if(rev[id]){
		Update_Rev(ls[id]);
		Update_Rev(rs[id]);
		rev[id] = 0;
	}
}
int Build(int l, int r, int fa){
	if(l > r) return -100;
	int mid = l + r >> 1;
	int id = New_Node(fa, str[mid]);
	ls[id] = maxs(ls[id], Build(l, mid-1, id));
	rs[id] = maxs(rs[id], Build(mid+1, r, id));
	Push_Up(id);
	return id;
}
void Rotate(int id, int kind){
	int fa = pre[id];
	Push_Down(fa);
	Push_Down(id);
	if(kind) ls[fa] = rs[id];
	else rs[fa] = ls[id];
	if(pre[fa])
		if(rs[pre[fa]] == fa)
			rs[pre[fa]] = id;
		else
			ls[pre[fa]] = id;
	pre[id] = pre[fa];
	if(kind)
		rs[id] = fa;
	else
		ls[id] = fa;
	pre[fa] = id;
	Push_Up(fa);
}
void Splay(int id, int god){
	Push_Down(id);
	while(pre[id] != god)
		if(pre[pre[id]] == god){
			Push_Down(pre[id]);
			Push_Down(id);
			Rotate(id, ls[pre[id]] == id);
		}
		else{
			Push_Down(pre[pre[id]]);
			Push_Down(pre[id]);
			Push_Down(id);
			int fa = pre[id];
			int kind = ls[pre[fa]] == fa;
			if((kind && rs[fa] == id) || (!kind && ls[fa] == id)){
				Rotate(id, !kind);
				Rotate(id, kind);}
			else{
				Rotate(fa, kind);
				Rotate(id, kind);}
		}
	Push_Up(id);
	if(!god) root = id;
}
int Get_Place(int id, int pl){
	Push_Down(id);
	int t = size[ls[id]] + 1;
	if(t == pl) return id;
	if(t > pl) return Get_Place(ls[id], pl);
	else return Get_Place(rs[id], pl-t);
}
void Add(int len){
	Splay(Get_Place(root, pos+1), 0);
	Splay(Get_Place(root, pos+2), root);
	ls[rs[root]] = maxs(ls[rs[root]], Build(0, len-1, rs[root]));
	Push_Up(rs[root]);
	Push_Up(root);
}
void Erase(int id){
	if(!id) return;
	s[++cnt] = id;
	Erase(ls[id]);
	Erase(rs[id]);
}
void Delete(int len){
	Splay(Get_Place(root, pos+1), 0);
	Splay(Get_Place(root, pos+len+2), root);
	Erase(ls[rs[root]]);
	pre[ls[rs[root]]] = 0;
	ls[rs[root]] = 0;
	Push_Up(rs[root]);
	Push_Up(root);
}
void Reverse(int len){
	Splay(Get_Place(root, pos+1), 0);
	Splay(Get_Place(root, pos+len+2), root);
	Update_Rev(ls[rs[root]]);
	Push_Up(rs[root]);
	Push_Up(root);
}
int main(){
	scanf("%d", &n);
	root = New_Node(0, ' ');
	rs[root] = New_Node(root, ' ');
	Push_Up(rs[root]);
	Push_Up(root);
	while(n--){
		char cmd[20];
		scanf("%s", cmd);
		switch(cmd[0]){
			case 'P':pos--;break;
			case 'N':pos++;break;
			case 'M':scanf("%d", &pos);break;
			case 'I':scanf("%d%*c", &x);gets(str);Add(x);break;
			case 'D':scanf("%d", &x);Delete(x);break;
			case 'R':scanf("%d", &x);Reverse(x);break;
			case 'G':putchar(key[Get_Place(root, pos+2)]);putchar('\n');break;
		}
	}
	return 0;
}

