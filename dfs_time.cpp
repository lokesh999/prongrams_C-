#include<bits/stdc++.h>
using namespace std;
vector<int> A[1000000],time_in(1000000,0),time_out(1000000,0);
bool visited[1000000];
int tt=1;
void dfs(int i)
{
    time_in[i]=tt++;
    visited[i]=true;
    for(int j=0;j<A[i].size();j++)
    {
        if(visited[A[i][j]]==0)
        {
            dfs(A[i][j]);
        }
    }
    time_out[i]=tt++;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(visited,false,n+1);
        int m;
        for(int i=0;i<n;i++)
        A[i].clear();
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            A[a-1].push_back(b-1);
            A[b-1].push_back(a-1);
        }
        int c=0;

        for(int i=0;i<n;i++ )
        {
            if(visited[i]==0)
            {
                c++;
                dfs(i);
            }
        }

        cout<<"Time in \n";
        for(int i=0;i<n;i++)
            cout<<time_in[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<time_out[i]<<" ";
        if(c)
        {
            cout<<"no. of connected components = "<<c<<endl;
        }
    }
    return 0;
}
