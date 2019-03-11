#include<bits/stdc++.h>
using namespace std;
vector<int> A(1e5+1,0),Rank(1e5+1,0);
int root(int x)
{
    if(A[x]==x)return x;
    return A[x]=root(A[x]);
}
void uni(int x,int y)
{
    int p=root(x);
    int q=root(y);
    if (p==q)return ;
    if(Rank[p]>=Rank[q])
    {
        Rank[p]+=Rank[q];
        A[q]=p;
    }
    else
    {
        Rank[q]+=Rank[p];
        A[p]=q;
    }
}
int main()
{
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        A[i]=i;Rank[i]=1;
    }
    char c;
    int x,y;
    for(int i=0;i<t;i++)
    {
        cin>>c;
        if(c=='M')
        {
            cin>>x>>y;
            uni(x,y);
        }
        else {
            cin>>x;
            cout<<Rank[root(x)]<<endl;
        }
    }
    return 0;
}
