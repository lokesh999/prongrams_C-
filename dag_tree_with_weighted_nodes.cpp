#include<bits/stdc++.h>
using namespace std;
vector<int> A[1000000],weight(1000000,0),parent(1000000,-1);
bool visited[1000000];
int total=0;
static int ff;
void dfs(int i)
{
    visited[i]=1;
    for(int j=0;j<A[i].size();j++)
    {
        if(visited[A[i][j]]==0)
        {
            parent[A[i][j]]=i;
            dfs(A[i][j]);
        }
    }
    for(int j=0;j<A[i].size();j++)
    {
        if(parent[i]!=A[i][j])
            weight[i]+=weight[A[i][j]];
    }
        if(::ff>max(weight[i],total-weight[i])) {
                ::ff= max(weight[i],total-weight[i]);
                }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int m;
        cin>>m;
        for(int i=0;i<n+1;i++)
        {
            A[i].clear();
            visited[i]=0;
            weight[i]=0;
            parent[i]=-1;
        }
        bool f=0;
        cout<<" press 1 for dag otherwise 0\n";
        cin>>f;
        for(int i=0;i<m;i++)
        {

            int a,b;
            cin>>a>>b;
            A[a-1].push_back(b-1);
            if(!f) A[b-1].push_back(a-1);
        }
        cout<<"enter the weights of the nodes\n";
        for(int i=0;i<n;i++)
            {
                cin>>weight[i];
                total+=weight[i];
            }
            ff = total+1;
        for(int i=0;i<n;i++ )
        {
            if(visited[i]==0)
            {
                parent[i]=i;
                dfs(i);
            }
        }
        cout<<"maximum minimal cost of edge cut is =  "<<ff<<endl;
    }
    return 0;
}
