#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long int> A(n),B(n);
        for(int i=0;i<n;i++)
        cin>>A[i];
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
    }
    return 0;
}

