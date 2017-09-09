#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,lowlink[101],pre[101],sccno[101],dep,scc,in[101],out[101],inc,outc;
stack<int> s;
vector<int> g[101];
void dfs(int u){
    pre[u]=lowlink[u]=++dep;
    s.push(u);
    for(int i=0;i<g[u].size();++i){
        int v=g[u][i];
        if(!pre[v]){
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v])lowlink[u]=min(lowlink[u],pre[v]);
    }
    if(lowlink[u]==pre[u]){
        ++scc;
        while(1){
            int x=s.top();s.pop();
            sccno[x]=scc;
            if(x==u)break;
        }
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        for(scanf("%d",&j);j;scanf("%d",&j))
            g[i].push_back(j);
    for(i=1;i<=n;++i)   if(!pre[i]) dfs(i);
    for(i=1;i<=n;++i)
        for(j=0;j<g[i].size();++j){
            int v=g[i][j];
            if(sccno[i]!=sccno[v]){
                ++in[sccno[v]];
                ++out[sccno[i]];
            }
        }
    for(i=1;i<=scc;++i){
        inc+=in[i]==0?1:0;
        outc+=out[i]==0?1:0;
    }
    if(scc==1)  puts("1\n0");
    else printf("%d\n%d\n",inc,max(inc,outc));
    return 0;
} 