#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > B[100000];
vector<int> disjoint_set(100000),dis(100000),visited;
int bfs(int i)
{
    int max_cost;
    queue<pair<int,int> > Q;
    Q.push({0,i});
    dis[i]=0;
    while(!Q.empty())
    {
        pair<int,int> p=Q.front();
        Q.pop();
        visited[p.second]=1;
        for(int t=0;t<B[p.second].size();t++)
        {
            if(visited[B[p.second][t].second]==0)
            {
            max_cost = max(p.first,B[p.second][t].first);
            Q.push({max_cost,B[p.second][t].second});
            dis[B[p.second][t].second]=max_cost;
            }
        }

    }
    return 0;
}
void init_disjoint_set(int n)
{
    for(int i=0;i<=n;i++)disjoint_set[i]=i;
}

int root(int i)
{
    if(disjoint_set[i]==i) return i;

    return disjoint_set[i]=root(disjoint_set[i]);
}
void uni(int x,int y)
{
    int p=root(x);
    int q=root(y);
    disjoint_set[p]=q;
}


int main()
{
    int n,m,mst,new_mst;
    bool flag=false;
    cout<<"no. of nodes\n";
    cin>>n;
    for(int i=0;i<=n;i++) B[i].clear();
    cout<<"no. of edges\n";
    cin>>m;
    vector<pair<pair<int,int>,pair<int,int> > > A;
    int x,y,cost;
    cout<<"Enter the edges of the graph\n";
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>cost;
        A.push_back({{1,cost},{x,y}});
    }
    sort(A.begin(),A.end());

    init_disjoint_set(n);
    mst=0;
    for(int i=0;i<m;i++)
    {
        if(root(A[i].second.first)!=root(A[i].second.second))
        {
            mst+=A[i].first.second;
            A[i].first.first=0;
            uni(A[i].second.first,A[i].second.second);
            B[A[i].second.first].push_back({A[i].first.second,A[i].second.second});
        B[A[i].second.second].push_back({A[i].first.second,A[i].second.first});
        }
    }

    for(int i=0;i<m;i++)
    {
        if(A[i].first.first==1)
        {
            visited.clear();
            visited.assign(n+1,0);
            bfs(A[i].second.first);
            if(dis[A[i].second.second] >=A[i].first.second)
            {
            flag =true;break;
            }
        }
    }
    /*
    sort(A.begin(),A.end());

    for(int i=0;i<n-1;i++)
    {
        init_disjoint_set(n);
        new_mst=0;
        for(int j=0;j<m;j++)
        {
            if(i==j)continue;
            if(root(A[j].second.first)!=root(A[j].second.second))
            {
                new_mst+=A[j].first.second;
                A[i].first.first=0;
                uni(A[j].second.first,A[j].second.second);
            }
        }
        if(new_mst==mst)
        {
            flag =true;break;
        }

    }*/
    if(flag) cout<<"unique mst not exist\n";
    else cout<<"unique mst exist\n";
    return 0;
}
