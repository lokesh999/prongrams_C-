#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        vector<int> A(101,0);
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=p;j++)
            {
                for(int k=1;k<=p;k++)
                {
                    A[(((n%i)%j)%k)%n]++;
                }
            }
        }
        for(int i=100;i>=0;i--)
        {
            if(A[i]){cout<<A[i]<<endl;break;}
        }
    }
    return 0;
}
