#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=20;
    while(i--)
    {
        int n,k;
        cin>>k;
    ifstream cin("input4.txt");

    set<int> A;
    int count =0;
    while(cin>>n)
    {
        A.insert(n);
        if(A.size()>k)
        {
            count++;
            A.clear();
            A.insert(n);
        }

    }
    if(!A.empty())count++;
    cout<<count<<endl;
    }
    return 0;
}
