#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,p;
        cin>>n>>m>>x;
        vector<int> A(n),B[m+1];
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<n;i++)
        {
            cin>>p;
            B[p].push_back(A[i]);
        }
        int dp[m+1][x+1];
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=-1;
            for(int j=1;j<=x;j++)
                dp[i][j]=0;
        }
        for(int j=1;j<=x;j++)
        {
            dp[1][j]=-1;
            for(int i=0;i<B[1].size();i++)
            {
                if(B[1][i]<=j)
                {
                    if(dp[1][j]<B[1][i]) dp[1][j]=B[1][i];
                }
            }
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<=x;j++)
            {
                dp[i][j]=-1;
                for(int k=0;k<B[i].size();k++)
                {
                    if(B[i][k]<j && dp[i-1][j-B[i][k]]>0)
                    {
                        dp[i][j]= max(dp[i][j],dp[i-1][j-B[i][k]]+B[i][k]);
                    }
                }
            }
        }

        if(dp[m][x]>0)
            cout<<x-dp[m][x]<<endl;
        else cout<<"-1\n";
    }
    return 0;
}
