#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
#define VERSON 1
using namespace std;
int n, m;
int main(int argc, char *argv[]){
	if(argc < 2){
		puts("�ļ�·��?(����ո�, scanf�㶮��)");
		scanf("%s", argv[1]);
	}
	freopen(argv[1], "r", stdin);
	scanf("%d", &n);
	if(!n)return puts("A problem has been ...����, Ӣ�ﲻ��(����)... ���ܶ�! Read Error!")*0;
	if(n > VERSON) return puts("�汾̫�ߣ��Ͱ汾�����ݣ�")*0;
	printf("������");
	for(int i = 0; i < 3; i++) Sleep(1000), printf(".");
	printf("\n���سɹ�����ʼ���ţ�\n");
	while(scanf("%d %d", &n, &m)!=EOF && n && m){
		m = 600 / m;
		n = 300 + n * 100;
		Beep(n, m);
	}
	printf("�������! 886!");
	Sleep(2000);
	return 0;
}

