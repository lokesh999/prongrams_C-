#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch;
    cin>>ch;
    vector<int> A;
    for(int i=0;i<ch.size();i++)
    {
        A.push_back(ch[i]-'0');
    }
    long long s,m=0;
    for(int j=0;j<A.size()-12;j++)
    {
        if(j==0 || A[j-1]==0)
        {
        s=A[j];
        for(int i=j+1;i<j+13;i++) s=s*A[i];
        }
        else
        {
            s=s/A[j-1];
            s=s*A[j+12];
        }
        if(m<s)m=s;
    }
    cout<<m<<endl;
    return 0;
}
