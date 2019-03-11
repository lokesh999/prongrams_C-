#include<bits/stdc++.h>
using namespace std;
vector<int> A(1000000,1),B;
void sieve()
{
    A[0]=0;A[1]=0;
    for(int i=2;i*i<=1000000;i++)
    {
        if(A[i])
        for(int j=i*2;j<=1000000;j+=i)
        {
            A[j]+=1;
        }
    }
    for(int i=2;i<1000000;i++)
        if(A[i])B.push_back(i);
}
int main()
{
    long long p=600851475143;
    set<int> S;
    set<int> ::iterator it;
    sieve();
    cout<<B.size()<<"Hello"<<endl;
    int i=0;
    while(p &&i<B.size())
    {
        if(p%B[i]==0)
        {
            p=p/B[i];
            S.insert(B[i]);
            cout<<p<<" ";
        }
        else i++;
    }
    cout<<endl;
    for(it=S.begin();it!=S.end();it++)
        cout<<*it<<" ";
    if(p)cout<<p;
    return 0;
}
