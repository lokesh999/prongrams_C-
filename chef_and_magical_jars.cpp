#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        long long sum=0;
        cin>>n;
        //vector<int> A(n);
        for(int i=0;i<n;i++)
        {
            cin>>p;
            sum+=p;
        }
        cout<<sum-n+1<<endl;
    }
    return 0;
}
