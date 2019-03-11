#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int n,k,a,b,lcm;
    while(t--)
    {
        cin>>n>>a>>b>>k;
        lcm = a*b/__gcd(a,b);
    if(n/a+n/b-2*(n/lcm)>=k)
        cout<<"Win\n";
    else cout<<"Lose\n";

    }

    return 0;
}
