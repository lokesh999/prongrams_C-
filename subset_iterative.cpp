
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        vector<int> vi;
        for(int j=0;j<n;j++)
        {
            if(i&1<<j) vi.push_back(j+1);
        }
        for(int k=0;k<vi.size();k++)cout<<vi[k]<<" ";
        cout<<endl;
    }
    return 0;
}
