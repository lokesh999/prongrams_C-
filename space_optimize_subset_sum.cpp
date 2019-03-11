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
        for(int i=0;i<n;i++)
            cin>>A[i];
        int m;
        cin>>m;
        int B[2][m+1];
        B[0][0]=1;
        B[1][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==0)
                {
                    if(A[i]==j) B[0][j]=1;
                    else B[0][j]=0;
                }
                else
                {
                    if(A[i]>j) B[i%2][j]=B[(i+1)%2][j];
                    else{
                        if(B[(i+1)%2][j]) B[i%2][j]=1;
                        else B[i%2][j]=B[(i+1)%2][j-A[i]];
                    }
                }
            }
        }
        for(int i=0;i<2;i++)
           {
              for(int j=0;j<=m;j++) cout<<B[i][j]<<" ";
        cout<<endl;
           }
           if(n%2)
           {
               if(B[0][m])cout<<"Yes\n";
               else cout<<"No\n";
           }
           else
           {

               if(B[1][m]) cout<<"Yes\n";
               else cout<<"No\n";
           }
    }
    return 0;
}
