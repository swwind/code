#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int qwq = 100000000;
struct BigInteger{
	int len, s[10050];
	BigInteger(){
		memset(s, 0, sizeof(s));
		len = 1;
	}
	BigInteger(int num){
		*this = num;
	}
	BigInteger(char *num){
		*this = num;
	}
	BigInteger operator = (ll num){
		char c[10050];
		sprintf(c, "%lld", num);
		*this = c;
		return *this;
	}
	BigInteger operator = (const char *num){
		len = strlen(num);
		for(int i = 0; i < len; i++)
			s[i] = num[len-1-i] - '0';
		return *this;
	}
	string str(){
		string res = "";
		for(int i = 0; i < len; i++)
			res = (char)(s[i]+'0') + res;
		return res;
	}
	void clean(){
		while(len > 1 && !s[len-1])
			len--;
	}
	BigInteger operator + (const BigInteger &b){
		BigInteger c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < len || i < b.len; i++){
			int x = g;
			if(i < len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % qwq;
			g = x / qwq;
		}
		return c;
	}
	BigInteger operator - (const BigInteger &b){
		BigInteger c;
		c.len = 0;
		int x;
		for(int i = 0, g = 0; i < len; i++){
			x = s[i] - g;
			if(i < b.len) x -= b.s[i];
			if(x >= 0) g = 0;
			else x += qwq, g = 1;
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	BigInteger operator * (const BigInteger &b){
		BigInteger c;
		c.len = len + b.len;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < b.len; j++)
				c.s[i+j] += s[i] * b.s[j];
		for(int i = 0; i < c.len-1; i++)
			c.s[i+1] += c.s[i] / qwq,
			c.s[i] %= qwq;
		c.clean();
		return c;
	}
	bool operator < (const BigInteger &b) const {
		if(len != b.len) return len < b.len;
		for(int i = len - 1; i >= 0; i--)
			 if(s[i] != b.s[i]) return s[i] < b.s[i];
		return 0;
	}
	BigInteger operator += (const BigInteger &b){
		*this = *this + b;
		return *this;
	}
	BigInteger operator -= (const BigInteger &b){
		*this = *this - b;
		return *this;
	}
	BigInteger operator *= (const BigInteger &b){
		*this = *this * b;
		return *this;
	}
	BigInteger operator + (const ll &b){
		BigInteger c = b;
		c += *this;
		return c;
	}
	BigInteger operator - (const ll &b){
		BigInteger c = b;
		c -= *this;
		return c;
	}
	BigInteger operator * (const ll &b){
		BigInteger c = b;
		c *= *this;
		return c;
	}
}a,b,c;
istream& operator >> (istream &in, BigInteger &x){
	string s;
	in >> s;
	x = s.c_str();
	return in;
}
ostream& operator << (ostream &out, BigInteger &x){
	out << x.str();
	return out;
}
int main(){
	cin >> a >> b;
	c = a * b;
	cout << c;
	return 0;
}

