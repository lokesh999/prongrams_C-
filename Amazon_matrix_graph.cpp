#include<bits/stdc++.h>
using namespace std;
bool  dfs(int A[][100],int n,int m,int i,int j)
{
    if(i>=0 && i<n  && j>=0 && j<m)
    {

    if(A[i][j]==0 )return false;
    else if(A[i][j]==9) return true;
    else if(A[i][j]==1)
    {
       return (dfs(A,n,m,i-1,j)||dfs(A,n,m,i+1,j)||dfs(A,n,m,i,j-1)||dfs(A,n,m,i,j+1));
    }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int A[100][100];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin>>A[i][j];
        }
        if(dfs(A,n,m,0,0)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
