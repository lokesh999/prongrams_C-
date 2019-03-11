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
        vector<int> A(n),LIS(n,1),LDS(n,1),Longest_bitonic(n);
        for(int i=0;i<n;i++)cin>>A[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(A[j]<A[i])
                {
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }

        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(A[j]<A[i])
                {
                    LDS[i]=max(LDS[i],LDS[j]+1);
                }
            }
        }
        for(int i=0;i<n;i++)
            Longest_bitonic[i]=LIS[i]+LDS[i]-1;
        cout<<*max_element(Longest_bitonic.begin(),Longest_bitonic.end())<<endl;
    }
    return 0;
}
