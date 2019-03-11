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
        int A[n];
        for(int i=0;i<n;i++)cin>>A[i];
        int B[n][n],C[n][n];
        for(int l=0;l<n;l++)
        for(int i=0;i<n-l;i++)
        {
            int j=i+l;
            if(l<2) B[i][j]=0;
            else if (l==2) {
                    B[i][j]=A[j]-A[i];
                    C[i][j]=i+1;
            }
            else
            {
                int mini=1e9;
                for(int k=C[i][j-1];k<=C[i+1][j];k++)
                {
                    if(mini>B[i][k]+B[k][j])
                       {
                           mini=B[i][k]+B[k][j];
                           C[i][j]=k;
                       }
                }
                B[i][j]=A[j]-A[i]+mini;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                cout<<B[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

