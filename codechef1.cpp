#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b,c,d;
    vector<int> A(n+1,10000);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        if(c)
        {
            cin>>d;
            if(A[a]>d)A[a]=d;
            if(A[b]>d)A[b]=d;
        }
        else
        {
            A[a]=0;
            A[b]=0;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=A[i];
    cout<<sum<<endl;
    return 0;
}
