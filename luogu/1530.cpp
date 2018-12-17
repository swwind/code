#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], cnt;
map<pair<int,int>,int>mp;
stringstream ss;
int main(int argc, char const *argv[]){
	int fz = read(), fm = read();
	ss << fz/fm << '.';
	fz = fz%fm*10;
	while(!mp[make_pair(fz/fm, fz%fm)]){
		// printf("%d %d = %d ...... %d\n", fz, fm, fz/fm, fz%fm);
		a[++cnt] = fz/fm;
		mp[make_pair(fz/fm, fz%fm)] = cnt;
		fz = fz%fm*10;
	}
	// printf("break: %d %d = %d ...... %d\n", fz, fm, fz/fm, fz%fm);
	int st = mp[make_pair(fz/fm, fz%fm)];
	if(fz%fm == 0){
		if(fz == 0 && cnt > 1) cnt--;
		for(int i = 1; i <= cnt; i++) ss << a[i];
	}
	else{
		for(int i = 1; i < st; i++) ss << a[i]; ss << '(';
		for(int i = st; i <= cnt; i++) ss << a[i]; ss << ')';
	}
	string qwq = ss.str();
	string::iterator ans=qwq.begin();
	int sum = 0;
	while(ans != qwq.end()){
		putchar(*ans++);
		if(++sum % 76 == 0) putchar('\n');
	} putchar('\n');
	return 0;
}
