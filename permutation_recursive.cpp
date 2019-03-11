#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> vi;
void gen()
{
   static vector<int> p(n+1,0);
    if(vi.size()==n)
    {
        for(int i=0;i<vi.size();i++)cout<<vi[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(p[i])continue;
            p[i]=1;
            vi.push_back(i);
            gen();
            p[i]=0;
            vi.pop_back();
        }

    }
}
int main()
{
    cin>>n;
    gen();
    return 0;
}
