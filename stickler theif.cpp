#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)cin>>A[i];
        A[1]=max(A[0],A[1]);
        for(int i=2;i<n;i++)
        {
            if(A[i]+A[i-2]>A[i-1])
                A[i]+=A[i-2];
            else A[i]=A[i-1];
        }
        cout<<max(A[n-1],A[n-2])<<endl;
    }
    return 0;
}
