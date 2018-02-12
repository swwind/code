#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
#define VERSON 1
using namespace std;
int n, m;
int main(int argc, char *argv[]){
	if(argc < 2){
		puts("文件路径?(别带空格, scanf你懂的)");
		scanf("%s", argv[1]);
	}
	freopen(argv[1], "r", stdin);
	scanf("%d", &n);
	if(!n)return puts("A problem has been ...算了, 英语不会(划掉)... 不能读! Read Error!")*0;
	if(n > VERSON) return puts("版本太高！低版本不兼容！")*0;
	printf("加载中");
	for(int i = 0; i < 3; i++) Sleep(1000), printf(".");
	printf("\n加载成功！开始播放！\n");
	while(scanf("%d %d", &n, &m)!=EOF && n && m){
		m = 600 / m;
		n = 300 + n * 100;
		Beep(n, m);
	}
	printf("播放完毕! 886!");
	Sleep(2000);
	return 0;
}

