#include<bits/stdc++.h>
using namespace std;
vector<int> A[100001];
vector<bool> visited(100001,false);
stack<int> top_sort;
void dfs(int i)
{
    visited[i]=true;
    for(int j=0;j<A[i].size();j++)
    {
        if(!visited[A[i][j]])
        {
            dfs(A[i][j]);
        }
    }
    top_sort.push(i);

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        if(!top_sort.empty())top_sort.pop();
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){A[i].clear();visited[i]=false;}
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            A[a].push_back(b);
        }
        cout<<"Assume node 1 as a source\n";
        dfs(1);
        cout<<"Topological sort is given as \n";
        while(!top_sort.empty())
        {
            cout<<top_sort.top()<<" ";
            top_sort.pop();
        }
        cout<<endl;
    }

    return 0;
}
