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
char op[N], work[N << 1];
int length, st[N], cnt, to[N];
int main(int argc, char const *argv[]) {
	scanf("%s", op + 1);
	length = strlen(op + 1);
	for (int i = 1; i <= length; i++) {
		switch (op[i]) {
		case '+': case '-': case '>': case '<': case '.': case ',': break;
		case '[': st[++cnt] = i; break;
		case ']':
			if (!cnt) {
				fprintf(stderr, "Compile error at position %d:\n'[' and ']' not mutched\n", i);
				exit(1);
			}
			to[st[cnt]] = i;
			to[i] = st[cnt];
			cnt --; break;
		default: fprintf(stderr, "Compile error at position %d:\nWhat is '%c'???\n", i, op[i]); exit(1);
		}
	}
	if (cnt) {
		fprintf(stderr, "Compile error at position %d:\n'[' and ']' not mutched\n", length);
		exit(1);
	}
	char * ptr = work + N;
	int pos = 1;
	getchar(); // read \n
	while (pos <= length) {
		if (op[pos] == '+') ++ * ptr;
		if (op[pos] == '-') -- * ptr;
		if (op[pos] == '.') putchar(* ptr);
		if (op[pos] == ',') * ptr = getchar();
		if (op[pos] == '<') -- ptr;
		if (op[pos] == '>') ++ ptr;
		if (op[pos] == ']') pos = to[pos];
		if (op[pos] == '[') if (!(* ptr)) pos = to[pos];
		pos ++;
	}
	return 0;
}