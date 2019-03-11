#include<bits/stdc++.h>
using namespace std;
vector<int> A[10],P(10,-1),discovery_time(10,0),low_time(10,100);
vector<bool>visited(10,0),AP(10,0);
int tt =0,pp=0,bb=0;
vector<pair<int,int> >bridge;
void dfs(int i)
{
    int child=0;
    visited[i]=true;
    //cout<<i<<" ";
    discovery_time[i]=tt;
    low_time[i]=tt;
    tt+=1;
//     cout<<discovery_time[i]<<" "<<low_time[i]<<endl;

    for(int j=0;j<A[i].size();j++)
    {
        if(visited[A[i][j]]==0)
        {
            child++;
            P[A[i][j]]=i;
            dfs(A[i][j]);
            //if(P[A[i][j]]!=A[i][j])
            low_time[i]=(low_time[i]<low_time[A[i][j]]?low_time[i]:low_time[A[i][j]]);
             //cout<<discovery_time[i]<<" "<<low_time[i]<<endl;
            if(P[i]==-1 && child>1){pp++;AP[i]=1;}
            else if(P[i]!=-1 && low_time[A[i][j]]>=discovery_time[i]){pp++;AP[i]=true;}
            if(low_time[A[i][j]]>discovery_time[i]){bb++;bridge.push_back({i,A[i][j]});}
        }
        else if(P[i]!=A[i][j])
            {
                low_time[i]=(low_time[i]<discovery_time[A[i][j]]? low_time[i]:discovery_time[A[i][j]]);
            }
    }

    for(int j=0;j<A[i].size();j++)
    {
        if(visited[A[i][j]]==0)
        {
            dfs(A[i][j]);
        }
    }
}
int main()
{
        int m;   // no. of nodes
        cin>>m;
        for(int i=0;i<m;i++){A[i].clear();visited[i]=0;}
        int n; // no. of edges
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int p,q;
            cin>>p>>q;
            A[p].push_back(q);
            A[q].push_back(p);
        }
        dfs(0);
        cout<<pp<<endl;
        for(int i=0;i<=m ;i++)
        {
            if(AP[i]) cout<<i<<" ";
        }
        sort(bridge.begin(),bridge.end());
        cout<<endl<<bb<<endl;
        for(int i=0;i<bb;i++)
          //  cout<<discovery_time[i]<<" "<<low_time[i]<<endl;
        cout<<bridge[i].first<<" "<<bridge[i].second<<endl;

    return 0;
}

