#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int B[n];
    for(int i=0;i<n;i++)cin>>B[i];
    cout<<"Enter the value of k\n";
    int k;
    cin>>k;
    int A[k+1][n+1];
    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<n+1;j++)A[i][j]=0;
    }
    for(int i=1;i<=k;i++)
    {
        int maxdiff=A[i-1][0]-B[0];
        for(int j=1;j<=n;j++)
        {
            maxdiff=max(maxdiff,A[i-1][j-1]-B[j-1]);
            A[i][j]=max(maxdiff+B[j],A[i][j-1]);
        }
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    int i=k,j=n-1;
    while(i>0 && j>0)
    {
        if(A[i][j]==A[i][j-1])j--;
        else
        {
            cout<<j+1<<endl;
            i--;j--;
        }
    }
    return 0;
}
