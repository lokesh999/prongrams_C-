#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
   vector< pair<int,pair<int,int> > >A;
    vector<int> dis(n+1,2e9);
    cout<<"enter the edges of the graph\n";
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        A.push_back({c,{a,b}});
    }
    int p;
    cout<<"Enter the source node\n";
    cin>>p;
    dis[p]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dis[A[j].second.second]>dis[A[j].second.first]+A[j].first)
                dis[A[j].second.second]=dis[A[j].second.first]+A[j].first;
        }
    }
    bool f=0;
    for(int j=0;j<m;j++)
        {
            if(dis[A[j].second.second]>dis[A[j].second.first]+A[j].first)
            {
                dis[A[j].second.second]=dis[A[j].second.first]+A[j].first;
                f=1;
                break;
            }
        }
        if(f) cout<<"negative cycle exits\n";
        else for(int i=1;i<=n;i++) cout<<dis[i]<<" ";


    return 0;
}
