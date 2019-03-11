#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long sum=0;
        vector<int> A(n);
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            sum+=A[i];
        }
        sort(A.begin(),A.end());
        int p=lower_bound(A.begin(),A.end(),k+1)-A.begin();
        for(int i=0;i<n-1;i++)
        {
            if(A[i]>k)
            {
            sum-=(A[i]-k)*2;
            A[i+1]-=(A[i]-k);
            }
        }

       cout<<sum<<endl;
    }
    return 0;
}
