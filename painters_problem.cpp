#include<bits/stdc++.h>
using namespace std;
int k_partition(const vector<int> sum,int mid)
{
    int p=1;
    for(int i=0;i<sum.size();i++)
    {
        if(sum[i]>mid)p++;
    }
    return p;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n),sum(n);
    for(int i=0;i<n;i++)cin>>A[i];
    sum[0]=A[0];
    for(int i=1;i<n;i++)sum[i]=A[i]+sum[i-1];
    int k;
    cout<<"enter total painters\n";
    cin>>k;
    int low= *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    while(low<high)
    {
        int mid = low+(high-low)/2;
        int p=k_partition(sum,mid);
        if(p<=k)high=mid;
        else low=mid+1;
    }
    cout<<low<<endl;

    return 0;
}
