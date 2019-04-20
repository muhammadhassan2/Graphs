#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>>edge;
int cost[100005],parent[100005];
bool visited[100005];
void BFS(int node)
{
  queue<int>q;
  q.push(node);
  visited[node]=true;
  cost[node]=0;
  while(!q.empty())
  {
      int from=q.front();
      q.pop();
      for(auto to:edge[from])
      {
          if(!visited[to])
          {
              visited[to]=true;
              q.push(to);
              cost[to]=cost[from]+1;
              parent[to]=from;
          }
      }
  }

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
        edge[to].push_back(from);
    }
  for(int i=1;i<=n;i++)
  {
      if(!visited[i])
      {
          BFS(i);
      }
  }
    return 0;
}
