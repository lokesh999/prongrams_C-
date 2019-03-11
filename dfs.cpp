#include<bits/stdc++.h>
using namespace std;
vector<int> A[100000],P(100000,-1),discovery_time(100000,0),low_time(100000,1000000);
vector<bool>visited(100000,0),AP(100000,0);
int tt =0;
void dfs(int i)
{
    int child=0;
    visited[i]=true;
    cout<<i<<" ";
    discovery_time[i]=tt;
    low_time[i]=tt++;
    for(int j=0;j<A[i].size();j++)
    {
        if(visited[A[i][j]]==0)
        {
            child++;
            P[A[i][j]]=i;
            dfs(A[i][j]);
            low_time[i]=(low_time[i]<low_time[A[i][j]]?low_time[i]:low_time[A[i][j]]);
            if(P[i]==-1 && child>1)AP[i]=1;
            else if(P[i]!=-1 && low_time[A[i][j]]>=discovery_time[i])AP[i]=true;
        }
        else if(P[i]!=A[i][j])
            {
                low_time[i]=(low_time[i]<discovery_time[A[i][j]]? low_time[i]:discovery_time[A[i][j]]);
            }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;   // no. of nodes
        cin>>m;
        for(int i=0;i<m+1;i++){A[i].clear();visited[i]=0;}
        int n; // no. of edges
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int p,q;
            cin>>p>>q;
            A[p].push_back(q);
            A[q].push_back(p);
        }
        int c=0;
        for(int i=1;i<=m;i++)
        {
            if(visited[i]==0)
            {
                dfs(i);
                c++;
            }
        }
        cout<<"\n no. of components "<<c<<endl;
        cout<<"Articulation points are : \n";
        for(int i=1;i<=m ;i++)
        {
            if(AP[i]) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
