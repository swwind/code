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
std::vector<pair<int, int>> ans;
priority_queue<int, vector<int>, greater<int>> q;
string str;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		cin >> str;
		if (str == "removeMin") {
			if (!q.size()) {
				ans.push_back(make_pair(1, 1));
			} else {
				q.pop();
			}
			ans.push_back(make_pair(3, 0));
		} else if (str == "insert") {
			int x = read();
			q.push(x);
			ans.push_back(make_pair(1, x));
		} else if (str == "getMin") {
			int x = read();
			while (q.size() && q.top() < x) {
				q.pop();
				ans.push_back(make_pair(3, 0));
			}
			if (!q.size() || q.top() != x) {
				q.push(x);
				ans.push_back(make_pair(1, x));
			}
			ans.push_back(make_pair(2, x));
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		if (x.first == 1)
			cout << "insert " << x.second << endl;
		else if (x.first == 2)
			cout << "getMin " << x.second << endl;
		else
			cout << "removeMin" << endl;
	}
	return 0;
}