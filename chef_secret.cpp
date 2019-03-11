#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n;
        p=n;
        vector<int> A(26,0);
        string ch;
        while(n--)
        {
            cin>>ch;
            set<char> s;
            for(int i=0;i<ch.size();i++)
            {
                s.insert(ch[i]);
            }
            for(auto it=s.begin();it!=s.end();it++)
            {
                A[*it-'a']++;
            }
        }
        int c=0;
        for(int i=0;i<26;i++)
            if(A[i]==p)c++;
        cout<<c<<endl;
    }
    return 0;
}
