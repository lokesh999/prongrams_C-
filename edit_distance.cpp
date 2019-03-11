#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch1,ch2;
    cin>>ch1>>ch2;
    int A[ch1.size()+1][ch2.size()+1];
    for(int i=0;i<=ch1.size();i++)
    {
        for(int j=0;j<=ch2.size();j++)
        {
            if(i==0) A[i][j]=j;
            else if(j==0) A[i][j]=i;
            else
            {
                if(ch1[i-1]==ch2[j-1])
                    A[i][j]=A[i-1][j-1];
                else
                {
                    A[i][j]=min(A[i-1][j-1],A[i][j-1]);
                    A[i][j]=1+min(A[i][j],A[i-1][j]);
                }
            }
        }
    }
    cout<<A[ch1.size()][ch2.size()];

    return 0;
}
