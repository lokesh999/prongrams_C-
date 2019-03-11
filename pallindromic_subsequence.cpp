#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string ch;
        cin>>ch;
        int A[ch.size()][ch.size()];
        for(int i=0;i<ch.size();i++)
        {
            for(int j=0;j<ch.size();j++)
            {
                if(i==j)A[i][i]=1;
                else A[i][j]=0;
            }
        }
        for(int l=1;l<ch.size();l++)
        {
            for(int j=l;j<ch.size();j++)
            {
                if(ch[j]==ch[j-1])
                {
                    A[j-l][j]=2+A[j-l+1][j-1];
                }
                else A[j-l][j]=max(A[j-l][j-1],A[j-l+1][j]);
            }
            for(int i=0;i<ch.size();i++)
        {
            for(int j=0;j<ch.size();j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        }
        for(int i=0;i<ch.size();i++)
        {
            for(int j=0;j<ch.size();j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
