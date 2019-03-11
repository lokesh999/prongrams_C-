#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        int t;
        cin>>t;
        if(t==0) break;
        int n;
        cin>>n;
        int A[n+2];
        A[0]=0;
        for(int i=1;i<=n;i++)cin>>A[i];
        A[n+1]=t;
        n=n+2;
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
        cout<<"The minimum cutting is "<<B[0][n-1]<<"."<<endl;
    }
    return 0;
}


