#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int n,p,q;
    cin>>n;
    vector<int> A(n),B(n),C(n);
    for(int i=0;i<n;i++)
        cin>>C[i];
    for(int i=0;i<n-1;i++ )
    {
        cin>>p;
        A[i]=C[p-1];
        C[p-1]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(C[i])
        {
            A[n-1]=C[i];
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<n;i++)
            B[i]=A[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(A[j]>A[i])B[j]=max(B[j],A[j]+B[i]);
            }
        }
        cout<<*max_element(B.begin(),B.end())<<endl;

    return 0;
}
