#include <bits/stdc++.h>
#define N 200020
#define SZ 20000020
#define mod 20170408
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct Matrix{
	#define MSZ 100
	ll num[MSZ][MSZ];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < MSZ; i++)num[i][i]=1;}
	ll* operator [] (int i) {return num[i];}
	friend Matrix operator * (Matrix a, Matrix b){
		Matrix c;
		for(int k = 0; k < MSZ; k++)
			for(int i = 0; i < MSZ; i++) if(a[i][k])
				for(int j = 0; j < MSZ; j++) if(b[k][j])
					c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b){
		Matrix c(true);
		for(;b;b/=2,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
bool mark[SZ];
int pri[SZ], cnt, s[120];
int main(int argc, char const *argv[]){
	int n = read(), m = read(), k = read();
	mark[1] = 1;
	for(int i = 2; i < SZ; i++){
		if(!mark[i]) pri[++cnt] = i;
		for(int j = 1; j <= cnt && i*pri[j] < SZ; j++){
			mark[i*pri[j]] = 1;
			if(i%pri[j] == 0) break;
		}
	}
	for(int i = 1; i <= m; i++) ++s[i%k];
	Matrix ans, tmp;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
			tmp[i][(i+j)%k] = s[j]%mod;
	ans[0][0] = 1;
	ans = ans*(tmp^n);
	int answer1 = ans[0][0];

	memset(s, 0, sizeof(int)*120);

	for(int i = 1; i <= m; i++) if(mark[i]) ++s[i%k];
	ans.clear(), tmp.clear();
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
			tmp[i][(i+j)%k] = s[j]%mod;
	ans[0][0] = 1;
	ans = ans*(tmp^n);
	int answer2 = ans[0][0];

	int ANS = ((answer1-answer2)%mod+mod)%mod;
	printf("%d\n", ANS);
	return 0;
}
// 所有数的可能性减去没有质数的可能性即可。
/*
最後(さいご)の电车(でんしゃ)を逃(に)して并(なら)んでる
うつむいた横(よこ)颜(かお)に君(きみ)の気持(きも)を探(さが)す
离(はな)れた间(ま)に仆(ぼく)らはいつも忘(わす)れるフリをしていた
谁(だれ)かを爱(あい)する优(やさ)しささえも　そっと记忆(きおく)にしまって
今(いま)　午前2时(ごぜんにじ)の交差点(こうさてん)で
あの顷(ころ)のように见(み)つめ合(あ)って
戻(もど)らない季节(きせつ)を取(と)り戻(もど)したいわけじゃない
だけど　今(いま)君(きみ)を见(み)てたい
変(か)わらない背(せ)中(なか)の少(すこ)し後(うし)ろを歩(ある)く
懐(なつ)かしいよ
振(ふ)り向(む)いて笑(わら)うのはどんな意味(いみ)かな
君(きみ)は何(なん)を思(おも)うの
记忆(きおく)の扉(とびら)が解(と)き放(はな)たれて　引(ひ)き寄(よ)せてしまいそうでも
同(おな)じ痛(いた)みを缲(く)り返(かえ)したくない　そうさ　このまま　このまま
今(いま)　午前2时(ごぜんにじ)の交差点(こうさてん)で
あの顷(ころ)よりも惹(ひ)かれ合(あ)って
あと一歩(いっぽ)进(すす)めば时计(とけい)の针(はり)も进(すす)む
だから　今(いま)抱(だ)きしめたい
触(ふ)れたい触(ふ)れられない距离(きょり)　问(と)い挂(か)ける目(め)も
多分(たぶん)もう隠(かく)せない　この想(おも)いで同(おな)じ颜(かお)をしている
君(きみ)といたい
ねえこんな日(ひ)を梦(ゆめ)见(み)てた
あの顷(ころ)よりもずっと强(つよ)く
探(さが)してた何(なん)かを见(み)つけた気(き)がしている
君(きみ)を　君(きみ)を
今(いま)　午前2时(ごぜんにじ)の交差点(こうさてん)で
あの顷(ころ)のように见(み)つめ合(あ)って
戻(もど)らない季节(きせつ)を取(と)り戻(もど)したいわけじゃない
だけど　今(いま)君(きみ)を见(み)てたい
本当(ほんとう)に大切(たいせつ)なモノに気(き)付(つ)けるまで
少(すこ)し长(なが)い时间(じかん)(とき)が过(す)ぎた
繋(つな)いだ手(て)は二度(にど)と离(はな)さないでそばにいてね
また君(きみ)とふたり
*/