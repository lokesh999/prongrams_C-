#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"enter the number of coins\n";
        int n;
        cin>>n;
        int A[n];
        cout<<"Enter the denomination (first must be 1)\n";
        for(int i=0;i<n;i++)
        cin>>A[i];
        cout<<"Enter the amount to pay\n";
        int m;
        cin>>m;
        int B[m+1];
        vector<int> C(m+1,1);
        for(int i=0;i<=m;i++)B[i]=i;
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if( i>= A[j] && B[i]> 1+ B[i-A[j]])
                   {
                    B[i]=1+B[i-A[j]];
                   }
                if(i>=A[j]) C[i]+=C[i-A[j]];

            }
        }
        for(int i=0;i<=m;i++)
        {
            cout<<C[i]<<" ";
        }
        cout<<"back tracking\n";
        int j=m;
        int i=n-1;
        while(i>=0)
        {
            if(i==0 && j)
            {
                cout<<j<<" one rupee coins ";
                break;
            }
            else if(B[j]==1+B[j-A[i]])
            {
                cout<<A[i]<<" " ;
                j-=A[i];
            }
            else i--;
        }

    }
    return 0;
}

