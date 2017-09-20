#include<iostream> 
using namespace std;
long long k,m,i,number=0,n;
int main ()
{
	cin>>k>>m;
	for (i=1;i<=k;i*=10)
		number+=k/i-i+1;
	number--;
	if (number>=m||k-(i/10)==0&&number<m-1)
		return puts("0")&0;
	for (i=k-(i/10),n=k;number<m-1;i*=10)
		number+=i,n*=10;
	cout<<max(n-number+m-2,k);
	return 0;
}