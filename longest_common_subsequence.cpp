#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x,y;
        cin>>x>>y;
        int A[x.size()+1][y.size()+1];
        for(int i=0;i<x.size()+1;i++)
        {
            A[i][y.size()]=0;
        }
        for(int i=0;i<y.size();i++)
        {
            A[x.size()][i]=0;
        }
        for(int i=x.size()-1;i>=0;i--)
        {
            for(int j=y.size()-1;j>=0;j--)
            {
                if(x[i]==y[j])
                {
                    A[i][j]=A[i+1][j+1]+1;
                }
                else A[i][j]=max(A[i][j+1],A[i+1][j]);
            }
        }
        int i=0,j=0;
        while(i!=x.size()||j!=y.size())
        {
            if(A[i][j]==max(A[i][j+1],A[i+1][j]))
            {
                if(A[i+1][j]>=A[i][j+1])i++;
                else j++;
            }
            else
            {
                cout<<x[i];
                i++;j++;
            }
        }
        cout<<endl;


    }
    return 0;
}
