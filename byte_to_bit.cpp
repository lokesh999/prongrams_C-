#include<bits/stdc++.h>
using namespace std;
long long int power(int base,int n)
{
    long long int y=1,x=base;
    while(n)
    {
        if(n%2)y=y*x;
        x=x*x;
        n=n/2;
    }
    return y;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long result = power(2,(n-1)/26);
        if(n%26>0 && n%26<3) cout<<result<<" 0 0\n";
        else if(n%26>2 && n%26<11) cout<<"0 "<<result<<" 0\n";
        else cout<<"0 0 "<<result<<endl;

    }

    return 0;
}
