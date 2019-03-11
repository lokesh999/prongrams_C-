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
        vector<int> A(n);
        for(int i=0;i<n;i++)cin>>A[i];
        int even =1,odd=0;
        long long sum=0,p;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum%2)odd++;
            else even++;
        }
        p=odd*even;
        cout<<p<<endl;
    }
    return 0;
}
