#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    bool f=0;
    cout<<"Press 1 for directed graph otherwise 0\n";

    while(t--)
    {
        cin>>f;
        cout<<"enter number of nodes\n";
        int n;
        cin>>n;
        vector<pair<int,int> > A[n+1];
        vector<bool> visited(n+1,0);
        int m;
        cin>>m;
        int sum=0;
        for(int i=0;i<m;i++)
        {

            int a,b,w;
            cin>>a>>b>>w;
            sum+=w;
            A[a].push_back({w,b});
            if(!f)A[b].push_back({w,a});
        }
        multiset<pair<int,int> > M;
        vector<int> distance(n+1,sum+1),parent(n+1,-1);
        cout<<"enter the source node\n";
        int p;
        cin>>p;
        M.insert({0,p});
        parent[p]=p;
        while(!M.empty())
        {
            pair<int,int> pp= *M.begin();
            int node= pp.second;
            int weight = pp.first;
            M.erase(M.begin());
            if(visited[node]==0)
            {
                visited[node]=1;
                distance[node]=weight;
                for(int i=0;i<A[node].size();i++)
                {
                    if(visited[A[node][i].second]==0)
                    {
                        if(distance[A[node][i].second]>distance[node]+A[node][i].first)
                        {
                                distance[A[node][i].second]=distance[node]+A[node][i].first;
                                parent[A[node][i].second]=node;
                                M.insert({distance[A[node][i].second],A[node][i].second});
                        }
                    }
                }
            }
        }
        cout<<" single source shortest path = \n";
        for(int i=1;i<n+1;i++)cout<<distance[i]<<" ";
        cout<<endl;
    }
    return 0;
}
