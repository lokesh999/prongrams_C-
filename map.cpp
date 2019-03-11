#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> m;
    m.insert({1,2});
    for(auto it =m.begin();it!=m.end();it++)
        cout<<it->first;
    return 0;
}
