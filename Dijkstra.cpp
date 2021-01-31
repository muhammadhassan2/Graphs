#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>>v(100005);
ll cost[100005],path[100005];
 int n,m;
ll dij()
{
    fill(cost,cost+100005,1e18);
    cost[1]=0;
    priority_queue<pair<ll,ll>>q;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        pair<ll,ll>y=q.top();
        q.pop();
        for(auto i:v[y.second])
        {
            if(i.second+cost[y.second]<cost[i.first])
            {
                cost[i.first]=i.second+cost[y.second];
                path[i.first]=y.second;
                q.push(make_pair(-cost[i.first],i.first));
            }
        }
    }
    return cost[n];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*
6 9
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 6 2
6 5 9
5 4 6
3 4 11

*/
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }

ll ans=dij();
//cout<<dij()<<endl;;
if(ans==1e18)return cout<<-1,0;
int in=n;
vector<int>pa;
while(in>=1)
{
    pa.push_back(in);
    in=path[in];
}
reverse(pa.begin(),pa.end());
for(auto i:pa)
cout<<i<<" ";

    return 0;
}
