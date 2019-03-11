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
        vector<int> A(n),B(n,1);
        for(int i=0;i<n;i++)
        cin>>A[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(A[j]>A[i])B[j]=max(B[j],B[i]+1);
            }
        }
        cout<<*max_element(B.begin(),B.end())<<endl;
    }
    return 0;
}
