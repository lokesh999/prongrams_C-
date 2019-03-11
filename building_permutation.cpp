#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,q;
    cin>>n;
    long int p;
    vector<long> A;
    vector<int> B(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>p;
        if(p<=n && p>0)
        {   q=p;
            if(B[q]==0)
            B [q]=1;
            else A.push_back(q);
        }
        else A.push_back(p);
    }
    sort(A.begin(),A.end());
    int j=A.size()-1;
    long long sum=0;
    for(int i=n;i>0;i--)
    {
        if(B[i]==0)
            sum+=abs(i-A[j--]);
    }
    cout<<sum<<endl;
    return 0;
}
