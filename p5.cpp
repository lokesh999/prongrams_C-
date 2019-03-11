#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int A[20];
    for(int i=0;i<20;i++)A[i]=i+1;
    long long int ans=A[0];
    for(int i=1;i<20;i++)
    {
        ans= (ans*A[i])/__gcd(ans,A[i]);
        cout<<ans<<" "<<i<<" "<<A[i]<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
