#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the cost of insertion,deletion and replacement \n";
    int in,de,re;
    cin>>in>>de>>re;
    cout<<"enter the string\n";
    string ch;
    cin>>ch;
    int n=ch.size();
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            A[i][j]=0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            if(ch[i]==ch[j])
            {
                A[i][j]=A[i+1][j-1];
            }
            else
            {
                A[i][j]=A[i+1][j-1]+re;
                int p= in+min(A[i+1][j],A[i][j-1]);
                int q= de+min(A[i+1][j],A[i][j-1]);
                p=min(p,q);
                A[i][j]=min(A[i][j],p);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
