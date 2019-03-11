#include<bits/stdc++.h>
using namespace std;
long  mod =1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> A(1000001,0);
        for(int i=0;i<n;i++)
        {
            int p;
            cin>>p;
            A[p]++;
        }
        long ans=1;
        for(int i=0;i<1000001;i++)
        {
            if(A[i])
            ans=(ans*A[i])%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
