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
        vector<int> A[n+1],time_in(n+1,0),time_out(n+1,0),visited(n+1,0);
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            A[a-1].push_back(b-1);
            A[b-1].push_back(a-1);
        }
        int tt=1;
        stack< int > S;
        S.push(0);
        visited[0]=1;
        cout<<endl;
        for(int i=0;i<n;i++) cout<<visited[i]<<" ";
        while(!S.empty())
        {
            int p=S.top();
            cout<<p<<endl;
            S.pop();
            if(visited[p]==1)
            {
                time_in[p]=tt++;
                visited[p]=2;
                S.push(p);
                for(int j=0;j<A[p].size();j++)
                {
                    if(visited[A[p][j]]==0)
                    {
                        S.push(A[p][j]);
                        visited[A[p][j]]=1;
                    }
                }
                continue;
            }
            else if(visited[p]==2)
            {
                time_out[p]=tt++;
                visited[p]=1;
            }

        }
        for(int i=0;i<n;i++) cout<<time_in[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<time_out[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<visited[i]<<" ";
    }
    return 0;
}
