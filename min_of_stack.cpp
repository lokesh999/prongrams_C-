#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,q=INT_MAX;
        cin>>n;
        stack<int> S;
        for(int i=0;i<n;i++)
        {
            cin>>p;
            if(S.empty())
            {
                S.push(p);
                q=p;
            }
            else if(p<q)
            {
                int y=2*p-q;
                S.push(y);
                q=p;
            }
            else S.push(p);
        }
        cout<<"press 1 for get min \n";
        cout<<"press 2 for pop\n";
        cin>>p;
        while(p==1 || p==2)
        {
            if(p==1)
                cout<<q<<endl;
            else
            {
                if(!S.empty())
                if(S.top()<q)
                {
                    cout<<"pop element = "<<q<<endl;
                    q= 2*q-S.top();
                    S.pop();
                }
                else
                {
                    cout<<"pop element = "<<S.top()<<endl;
                    S.pop();
                }
                else cout<<"no element for deletion\n";
            }
            cin>>p;
        }
    }
    return 0;
}
