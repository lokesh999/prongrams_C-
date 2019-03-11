#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m;
        int A[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==j)A[i][j]=1;
               else  A[i][j]=0;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            A[a][b]=1;
            A[b][a]=1;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++ )
                A[i][j]=(1+A[i][j])%2;
        }

        vector<int> visited(n+1,0),parent(n+1,0);
        queue<int> Q;
        bool flag=true;
        for(int j=1;j<=n;j++)
        {
            if(!visited[j])
            {
                Q.push(j);
                visited[j]=1;
            }
        while(!Q.empty())
        {
            int p=Q.front();
            Q.pop();
            for(int i=1;i<=n;i++)
            {
                if(p!=i && A[p][i])
                {
                    if(!visited[i])
                    {
                        if(visited[p]==1)
                            visited[i]=2;
                        else visited[i]=1;
                        Q.push(i);
                    }
                    else
                    {
                        if(visited[i]==visited[p])
                        {
                            flag=false;
                            break;
                        }
                    }
                }
            }

        }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";



    }
    return 0;
}
