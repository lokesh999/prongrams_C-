#include<bits/stdc++.h>
using namespace std;
vector<int> A[100001],mark(100001,0);

void dfs(int i,int cc)
{
    if(!mark[i])
    {
        mark[i]=cc;
        for(int it=0;it<A[i].size();it++)
        {
            if(!mark[A[i][it]])
            {
                dfs(A[i][it],cc);
            }
        }
    }
}

int palindrome(vector<int> B)
{
    int n=B.size();
    int A[n];
    for(int i=n-1;i>=0;i--)
    {
        int back_up=0;
        for(int j=i;j<n;j++)
        {
            if(i==j) A[j]=1;
            else if(B[i]==B[j] || mark[B[i]]==mark[B[j]])
            {
                int temp=A[j];
                A[j]=2+back_up;
                back_up=temp;
            }
            else
            {
                back_up = A[j];
                A[j]=max(A[j-1],A[j]);
            }
        }

    }
    return A[n-1];
    /*
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++) A[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
        A[i][i]=1;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            if(B[i]==B[j] || mark[B[i]]==mark[B[j]])
            {
                    A[i][j]=2+A[i+1][j-1];
            }
            else
            {
                A[i][j]= max(A[i][j-1],A[i+1][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cout<<A[i][j]<<" ";
    cout<<endl;
    return A[0][n-1];
    */
}

int main()
{
    int n,m,k,x,y;
    cin>>n>>m>>k;
    vector<int> B(k);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    int cc=1;
    for(int i=0;i<k;i++)cin>>B[i];
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            dfs(i,cc);
            cc++;
        }
    }
    cout<<palindrome(B)<<endl;

    return 0;
}
