#include<bits/stdc++.h>
using namespace std;
#define ma 100
bool bfs(int rgraph[ma][ma],int s,int t,int parent[])
{
    vector<int> visited(ma,0);
    queue<int> Q;
    Q.push(s);
    visited[s]=1;
    parent[s]=-1;
    while(!Q.empty())
    {
        int u= Q.front();Q.pop();
        {
            for (int v=0;v<ma;v++)
            {
                if(visited[v]==false && rgraph[u][v]>0)
                {
                    Q.push(v);
                    visited[v]=1;
                    parent[v]=u;
                }
            }
        }
    }
    return visited[t]==true;

}
int dinic(int rgraph[ma][ma],int s,int t)
{
    int flo=0;
    int parent[ma];
    //memset(parent,0,sizeof(parent));
    while(bfs(rgraph,s,t,parent))
    {
        int flow= INT_MAX;
        for(int i=t;i!=s;i=parent[i])
        {
            flow= min(flow,rgraph[parent[i]][i]);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            rgraph[u][v]-=flow;
            rgraph[v][u]+=flow;
        }
        flo+=flow;
    }

    return flo;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int graph[ma][ma];
        memset(graph,0,sizeof(graph[0][0])*ma*ma);
        int edges,a,b,c;
        cin>>edges;
        for(int i=0;i<edges;i++)
        {
            cin>>a>>b>>c;
            graph[a][b]=c;
        }
        int s,t;
        cin>>s>>t;
        cout<<"max flow ="<<dinic(graph,s,t);

    }
    return 0;
}

