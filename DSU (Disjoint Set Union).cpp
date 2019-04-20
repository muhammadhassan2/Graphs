#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>>v(100005);
int root[100005];
int Dsu(int node)
{
    if(root[node]==node)
        return node;
    return root[node]=Dsu(root[node]); //Path compression optimization
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=0;i<=n;i++)root[i]=i;
 for(int i=0;i<m;i++)
 {
     int a,b;
     cin>>a>>b;
     int a1=Dsu(a);
     int b1=Dsu(b);
     root[a]=b;
 }

    return 0;
}
