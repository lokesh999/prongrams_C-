#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MAX 8000

long long int A[MAX];
long long int dp[MAX][800];
long long int cs[MAX];

void cumulativeSum()
{
    cs[0]=0;
    for(int i=1;i<MAX;i++)
        cs[i]=cs[i-1]+A[i];
}
void intialize()
{
    for(int i=0;i<MAX;i++)
        dp[1][i]=cs[i]*(i);
}

long long int cost(int i,int j)
{
    if(i>j)
        swap(i,j);
    return (cs[j]-cs[i-1])*(j-i+1);
}

void ComputeDP(int i,int leftj,int rightj,int leftk,int rightk)
{
    if(leftj>rightj)return ;
    int midj=(leftj+rightj)/2;
    dp[i][midj]=INF;
    int optk;

    for(int k=leftk;k<=midj;k++)
    {
        if(dp[i][midj]>dp[i-1][k]+cost(k+1,midj))
        {
            dp[i][midj]=dp[i-1][k]+cost(k+1,midj);
            optk=k;
        }
    }
    ComputeDP(i,leftj,midj-1,leftk,optk);
    ComputeDP(i,midj+1,rightj,optk,rightk);
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>A[i];
    cumulativeSum();
    intialize();
    for(int i=2;i<=k;i++)
    {
        ComputeDP(i,1,n,1,n);
    }
   /* for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    */
    cout<<dp[k][n]<<endl;
}

