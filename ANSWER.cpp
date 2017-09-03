#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<list>
#include<map>
#include<set>
#include<list>
#include<stack> 
using namespace std;
int n,A,B;//n:
int m;
int i,j;
struct node
{
    int s;//目前这台机器 完成目前物品 结束的时间 
    int v;//该机器速度 
    bool operator<(node k)const
    {
        return s>k.s;
    } //小根堆 
};
priority_queue<node> q; 
int t[2000]; 
int ans;
int main()
{
    // freopen("job.in","r",stdin);
    // freopen("job.out","w",stdout);
    scanf("%d%d%d",&n,&A,&B); 
    node x;
    for (i=1;i<=A;i++)
    {
        scanf("%d",&x.v);
        x.s=x.v;
        q.push(x);//把速度压入优先队列中  
    }
    for (i=1;i<=n;i++)
    {
        x=q.top();//取出最小值 
        q.pop();//把最小值弹出 
        t[i]=x.s;//t[i]存的是第i个物品完成操作A 结束的时间 
        x.s+=x.v;//然后下一个物品要用这台机器 结束的时间就要+x.v 
        q.push(x);//再次压入栈 
    } 
    while (!q.empty()) q.pop(); 
    for (i=B;i>=1;i--)
    {
        scanf("%d",&x.v);
        x.s=x.v;
        q.push(x);
    } 
    ans=0;
    for (i=n;i>=1;i--)
    {
        x=q.top();//取出最小值 
        q.pop();//把最小值弹出 
        printf("%d\n", x.s);
        if (x.s+t[i]>ans) ans=x.s+t[i];//求最晚结束时间 
        x.s+=x.v;//然后下一个物品要用这台机器 结束的时间就要+x.v 
        //然而似乎开始用这台机器的操作该物品时候，可能上一个物品用这台 
        //机器已经完成任务了，然而这并不影响QAQ 
        q.push(x);
    }
    printf("%d %d\n",t[n],ans); 
    return 0;
}