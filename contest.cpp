#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long a,b;
    vector<pair<long int,int> >B;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        B.push_back({a,1});
        B.push_back({b+1,-1});
    }
    sort(B.begin(),B.end());
    long int m=0,sum=0;
    for(int i=0;i<B.size();i++)
    {
       sum+=B[i].second;
       if(m<sum)m=sum;
    }
    cout<<m<<endl;
}
