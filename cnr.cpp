#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int fastexpo(int n,int r)
{
    long long result =1,x=n;
    while(r)
    {
        if(r%2)
        {
            result = (result*x)%p;
        }
        x=(x*x)%p;
        r=r/2;
    }
    return result;
}
int infac(int n)
{
    if(n==1) return 1;
    return fastexpo(n,p-2);
}
int main()
{
    int t;
    cin>>t;
    long long int A[1001];
    long long int B[1001];
    A[0]=1;
    A[1]=1;
    A[2]=2;
    A[3]=6;
    B[0]=1;B[1]=1;
    for(int i=4;i<1001;i++)
    {
        A[i]=(i*A[i-1])% p;
    }
    for(int i=2;i<1001;i++)
        B[i]=infac(A[i]);
    while(t--)
    {
        int n,r;
        cin>>n>>r;
       // cout<<A[n]<<" "<<A[n-r]<<" "<<A[r]<<endl;
       int ans;
       if(n>=r)
        ans = (A[n]*B[n-r]%p*B[r]%p)%p;
        else ans=0;
        cout<<ans<<endl;

    }

    return 0;
}
