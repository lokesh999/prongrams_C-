#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>k>>n;
        if(k==1){cout<<n<<endl; continue;}
        int A[n+1][k+1];
        for(int i=0;i<=k;i++)
           {
             A[0][i]=0;
             A[1][i]=1;
           }
        for(int i=0;i<=n;i++)
         {
             A[i][1]=i;
             A[i][0]= -1;
         }
         A[0][0]=0;

        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                int p=1e9;
                for(int x=1;x<i;x++)
                {
                    if(p>max(A[x-1][j-1],A[i-x][j]))
                        p=max(A[x-1][j-1],A[i-x][j]);
                }
                A[i][j]=p+1;
            }
        }
        cout<<A[n][k]<<endl;
    }
    return 0;
}
