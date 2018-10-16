#include <bits/stdc++.h>
using namespace std;
char str[20];
int main(int argc, char const *argv[]) {
	scanf("%s", str+1);
	int len = strlen(str+1);
	int l = 1, r = len;
	int ans = 0;
	while (l <= r)
		ans += str[l++] != str[r--];
	puts(ans == 1 || ans == 0 && (len&1) ? "YES" : "NO");
	return 0;
}