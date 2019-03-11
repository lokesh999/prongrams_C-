#include<bits/stdc++.h>
using namespace std;
bool comp(string a,string b)
{

    return a+b>b+a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> ch(n);
        for(int i=0;i<n;i++) cin>>ch[i];
        sort(ch.begin(),ch.end(),comp);
        for(int i=0;i<n;i++)cout<<ch[i]<<" ";
        cout<<endl;
    }
}
