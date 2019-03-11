#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    int p;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        if(p<r)cout<<"Bad boi\n";
        else cout<<"Good boi\n";
    }
    return 0;
}
