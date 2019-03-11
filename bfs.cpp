#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    cin>>t;
    while(t--)
    {
        int m;
        cout<<"enter the no. of nodes in the graph\n";
        cin>>m;
        int a,b;
        char p,r;
        vector<char> A[m+1];
        vector<bool> visited(m+1,0);
        vector<int> parent(m+1,-1);
        queue<int> q;
        int n;
        cout<<"enter the no. of edges\n";cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>p>>r;
            A[p-'a'].push_back(r-'a');
            A[r-'a'].push_back(p-'a');
        }
        q.push(A[0][0]);
        visited[A[0][0]]=1;
        while(1)
        {
        while(!q.empty())
        {
            char ch= q.front();q.pop();
            ch+='a';
            cout<<ch<<" "<<(parent[ch-'a']>-1?char(parent[ch-'a']+'a'):'n')<<endl;
            for(int i=0;i<A[ch-'a'].size();i++)
            {
                if(visited[A[ch-'a'][i]]==0)
                {
                    visited[A[ch-'a'][i]]=1;
                    parent[A[ch-'a'][i]]=int(ch-'a');
                    q.push(A[ch-'a'][i]);
                }
            }
        }
            for(int i=0;i<m;i++)
            {
                if(visited[i]==0)
                {
                    q.push(i);
                    c++;
                    visited[i]=1;
                    break;
                }
            }
            if(q.empty())break;
            cout<<endl;
        }
        cout<<"no. of connected components = "<<c<<endl;
    }

    return 0;
}
