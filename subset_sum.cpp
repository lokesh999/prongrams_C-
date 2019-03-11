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
        {
            cin>>A[i];
        }
        cout<<"enter the sum to be check\n";
        int m;
        cin>>m;
        bool B[n][m+1],C[2][m+1];
        for(int i=0;i<n;i++) B[i][0]=true;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==0)
                {
                    if(A[i]==j)B[i][j]=true;
                    else B[i][j]=false;
                }
                else
                {
                    if(A[i]>j)B[i][j]=B[i-1][j];
                    else if(B[i-1][j])
                        B[i][j]=true;
                    else B[i][j]=(B[i-1][j-A[i]]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
                cout<<B[i][j]<<" ";
            cout<<endl;
        }
        int j=m;
        cout<<j<<endl;
        int i=n-1;
        if(B[i][j])
        while(j>0&& i>=1)
        {
            if( j-A[i]>=0 && B[i][m]==B[i-1][m-A[i]])
            {cout<<A[i]<<" ";
             j-=A[i--];
             }
            else i--;
        }
        if(i==0 && B[i][j]) cout<<A[i];
    }
    return 0;
}
