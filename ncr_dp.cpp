#include<bits/stdc++.h>
using namespace std;
int p=1e9+7;
int main()
{
    vector< long int> A[1001];
    for(int i=1;i<1001;i++)
    {
        for(int j=0;j<=i/2;j++)
        {
            if(j==0)
                A[i].push_back(1);
            else if(j<=(i-1)/2)
                A[i].push_back((A[i-1][j-1]+A[i-1][j])%p);
            else
                A[i].push_back((A[i-1][j-1])<<1%p);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n>>r;
        if(n>=r)
        {
            if(n==r)cout<<"1\n";
            if(r>n/2)
            {
                cout<<A[n][n-r]<<endl;
            }
            else cout<<A[n][r]<<endl;
        }
        else cout<<"0\n";
    }
    return 0;
}
