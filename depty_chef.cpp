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
        vector<int> A(n),B(n);
        for(int i=0;i<n;i++)cin>>A[i];

        for(int i=0;i<n;i++)cin>>B[i];
        for(int i=1;i<n-1;i++)
        {
            if(B[i]<=A[i-1]+A[i+1])B[i]=-1;
        }
        if(A[1]+A[n-1]>=B[0])B[0]=-1;
        if(A[n-2]+A[0]>=B[n-1])B[n-1]=-1;
        cout<<*max_element(B.begin(),B.end())<<endl;
    }
    return 0;
}
