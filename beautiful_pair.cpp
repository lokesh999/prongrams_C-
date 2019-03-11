#include<bits/stdc++.h>
using namespace std;
vector<int> B[10000];
int dfs(int i,int A[])
{
    static int c=0;
    static multiset<int> multi;
    multi.insert(A[i-1]);
    for(int j=0;j<B[i].size();j++)
    {
        cout<<B[i][j]<<" j\n";
        dfs(B[i][j],A);
    }
    multiset<int> ::iterator it = upper_bound(multi.begin(),multi.end(),i),p; p=it;
     if(it!=multi.end())cout<<*it<<endl;
    while(it!=multi.end()){c++;++it;}
    multi.erase(--p);
    cout<<c<<" "<<multi.size()<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        cout<<"enter the weights of each nodes\n";
        for(int i=0;i<n;i++)
            cin>>A[n];
        for(int i=0;i<=n;i++)B[i].clear();
        cout<<"Enter the directed edges of the tree\n";
        int a,b;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            B[a].push_back(b);
        }
        int s=1;
        cout<<" beautiful pairs = "<<dfs(s,A)<<endl;
    }
    return 0;
}
