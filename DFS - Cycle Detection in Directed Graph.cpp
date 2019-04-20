#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>>edge;
int tim[100005];
void dfs(int node)
{
    tim[node]=1;
    for(auto i:edge[node])
    {
        if(!time[i]==0)
        {
            dfs(i);
        }
        else if(tim[node]==1)
        {
            cout<<"Cycle found "<<node<<" "<<i<<endl;
        }
    }
    tim[node]=2;
}
int main()
{
    int n,m;
    cin>>n>>m;
    edge.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int from,to;
        cin>>from>>to;
        edge[from].push_back(to);
    }
    for(int i=1;i<=n;i++)
        if(tim[i]!=0)
        dfs(i);
    return 0;
}
