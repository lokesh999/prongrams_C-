#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    int B[n];
    int A[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)A[i][j]=0;
    }
    for(int i=0;i<n;i++) cin>>B[i];
    cout<<"enter the directed edges\n";
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        A[a][b]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(A[j][i]+A[i][k]==2)A[j][k]=1;
            }
        }
    }
    int  max=-1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i][j])
            {
                if(max<B[j-1]-B[i-1])max=B[j-1]-B[i-1];
            }

        }
    }
    cout<<max<<endl;
    return 0;
}
