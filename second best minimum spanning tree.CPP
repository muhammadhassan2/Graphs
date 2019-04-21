#include <bits/stdc++.h>

using namespace std;
int pa[2000];
int dsu(int n)
{
    if(pa[n]==n)return n;
    else return pa[n]=dsu(pa[n]);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<2000;i++)pa[i]=i;
    pair<pair<int,int>,pair<int,int>>p[2000];
    for(int i=0;i<m;i++)
    {
        cin>>p[i].second.first>>p[i].second.second>>p[i].first.first;
        p[i].first.second=0;
    }
    sort(p,p+m);
    int c=0,ma=100000;
    bool l=0;
    for(int i=0;i<m;i++)
    {
        int a=dsu(p[i].second.first);
        int b=dsu(p[i].second.second);
        if(pa[a]!=pa[b])
        {
            c+=p[i].first.first;
            p[i].first.second=1;
            a=dsu(a);
            b=dsu(b);
            pa[b]=a;
        }
   }
int mmm=100000;
for(int j=0;j<m;j++){
           int t=0;
    for(int k=0;k<2000;k++)pa[k]=k;
    for(int i=0;i<m;i++)
    {
       if(i==j){
        continue;}
        int a=dsu(p[i].second.first);
        int b=dsu(p[i].second.second);
        if(pa[a]!=pa[b])
        {
            t+=p[i].first.first;
            a=dsu(a);
            b=dsu(b);
            pa[b]=a;
        }
   }
if(p[j].first.second&&t>=c)
mmm=min(mmm,t);
    }
    cout<<c<<" "<<mmm<<endl;
    }

    return 0;
}
