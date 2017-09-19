#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=1000;
int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct data{
    int id,st,t,rk;
    bool operator <(const data &r)const{
        if(rk==r.rk) return st>r.st;
        return rk<r.rk;
    }
    data(int a,int b,int c,int d):id(a),st(b),t(c),rk(d){} 
};
priority_queue<data> q;
int id,st,t,rk,T=0;
int main(){
    while(scanf("%d",&id)!=EOF){
        st=read();t=read();rk=read();
        while(T<st&&!q.empty()){
            data now=q.top();q.pop();
            T=max(now.st,T);
            int s=min(now.t,st-T);//now 结束和新的开始谁更先 
            T+=s;
            now.t-=s;
            if(now.t) q.push(now);
            else printf("%d %d\n",now.id,T);
        }
        data nw=data(id,st,t,rk);
        q.push(nw);
    }
    while(!q.empty()){
        data now=q.top(); q.pop();
        printf("%d %d\n",now.id,T+=now.t);
    }
    return 0;
}