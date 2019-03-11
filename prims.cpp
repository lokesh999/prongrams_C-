#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > A[n+1];
        int m;
        long long sum =0;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            sum+=w;
            A[a].push_back({w,b});
            A[b].push_back({w,a});
        }
        multiset<pair<int,int> > multi;
        vector<int> parent(n+1,-1);
        vector<bool > visited(n+1,0);
        vector<long long> distance (n+1,sum+1);
        cout<<"enter the source of the spanning tree\n";
        int p;
        cin>>p;
        multi.insert({0,p});
        parent[p]=p;
        while(!multi.empty())
        {
            pair<int,int> pp = *multi.begin();
            int node = pp.second;
            int weight= pp.first;
            multi.erase(multi.begin());
            if(visited[node]==0)
            {
            visited[node]=1;
            distance[node]=weight;

            for(int i=0;i<A[node].size();i++)
            {
                if(visited[A[node][i].second]==0)
                {
                    if(distance[A[node][i].second]> A[node][i].first)
                    {
                         distance[A[node][i].second]=A[node][i].first;
                         parent[A[node][i].second]=node;
                         multi.insert({distance[A[node][i].second],A[node][i].second});
                    }
                }
            }
            }
        }
        sum=0;
        for(int i=0;i<n+1;i++)
            {
                sum+=distance[i];
            }
            cout<<"cost of minimum spanning tree = "<<sum<<endl;
            cout<<"edges are \n";
        for(int i=1;i<n+1;i++)
        {
            if(i!=parent[i])
            cout<<i<<" "<<parent[i]<<endl;
        }

    }
    return 0;
}
