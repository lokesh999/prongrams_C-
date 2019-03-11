#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   vector<int> vi;
   for(int i=0;i<n;i++)
    {
        vi.push_back(i+1);
    }
    do
    {
        for(int i=0;i<vi.size();i++)cout<<vi[i]<<" ";
        cout<<endl;
    }while(next_permutation(vi.begin(),vi.end()));
    return 0;
}
