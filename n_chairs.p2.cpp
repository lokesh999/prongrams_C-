#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int B[n];
    for(int i=0;i<n;i++ )
        cin>>B[i];
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)A[i][j]=1e9;
    }
    for(int i=0;i<n;i++)
    {
        A[i][(i+B[i])%n]=1;
        A[i][(i-B[i]+n)%n]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(A[j][k]>A[j][i]+A[i][k])
                    A[j][k]=A[j][i]+A[i][k];
            }
        }
    }
    cout<<endl<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
