// 请无视

#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
#define VERSON 1
using namespace std;
int n, m;
int main(int argc, char *argv[]){
	if(argc < 2){
		puts("ÎÄ¼þÂ·¾¶?(±ð´ø¿Õ¸ñ, scanfÄã¶®µÄ)");
		scanf("%s", argv[1]);
	}
	freopen(argv[1], "r", stdin);
	scanf("%d", &n);
	if(!n)return puts("A problem has been ...ËãÁË, Ó¢Óï²»»á(»®µô)... ²»ÄÜ¶Á! Read Error!")*0;
	if(n > VERSON) return puts("°æ±¾Ì«¸ß£¡µÍ°æ±¾²»¼æÈÝ£¡")*0;
	printf("¼ÓÔØÖÐ");
	for(int i = 0; i < 3; i++) Sleep(1000), printf(".");
	printf("\n¼ÓÔØ³É¹¦£¡¿ªÊ¼²¥·Å£¡\n");
	while(scanf("%d %d", &n, &m)!=EOF && n && m){
		m = 600 / m;
		n = 300 + n * 100;
		
		Beep(n, m);
	}
	printf("²¥·ÅÍê±Ï! 886!");
	Sleep(2000);
	return 0;
}

