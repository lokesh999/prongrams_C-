#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long > A(n);
    vector<long long> B(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    B=A;
    sort(B.begin(),B.end());
    for(int i=1;i<n;i++)
    {
        B[i]+=B[i-1];
        A[i]+=A[i-1];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            if(b==1)cout<<A[--c]<<endl;
            else cout<<A[--c]-A[b-2]<<endl;
        }
        else
        {
            if(b==1)cout<<B[--c]<<endl;
            else cout<<B[--c]-B[b-2]<<endl;
        }
    }
    return 0;
}
