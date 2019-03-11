#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n][n],B[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
            B[j][n-1-i]=A[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
            cout<<B[i][j];
        cout<<endl;
    }

    return 0;
}
