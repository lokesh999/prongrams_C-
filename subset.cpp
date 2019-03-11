#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
void gen(int k)
{
    if(k==n+1)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        gen(k+1);
        v.push_back(k);
        gen(k+1);
        v.pop_back();
    }
}
int main()
{
    cin>>n;
    gen(1);
    return 0;
}
