#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<bool> cnt(1e6+1,0),cnt1(1e6+1,0);
    vector<int> A(1e6+1,0),B(1e6+1,0);
    int p;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        cnt[p]=true;
    }
    for(int i=0;i<n;i++)
    {
        cin>>p;
        cnt1[p]=true;
    }
    for(int i=1;i<1e6+1;i++)
    {
        {
            for(int j=i;j<=1e6;j+=i)
            {
                if(cnt[j])
                    A[i]=max(A[i],j);
            }
        }
    }

    for(int i=1;i<1e6+1;i++)
    {

        {
            for(int j=i;j<=1e6;j+=i)
            {
                if(cnt1[j])
                    B[i]=max(j,B[i]);
            }
        }
    }
    int mx;
    for(int i=1;i<=1e6;i++)
    {
        if(A[i]&&B[i])mx=i;
    }
    cout<<A[mx]+B[mx];
    return 0;
}
