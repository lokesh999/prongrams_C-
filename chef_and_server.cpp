#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,q,r;
        cin>>p>>q>>r;
        if(((p+q)/r)%2==0)cout<<"CHEF\n";
        else cout<<"COOK\n";
    }
    return 0;
}

