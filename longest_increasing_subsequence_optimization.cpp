#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)cin>>A[i];
        vector<int> B;
        for(int i=0;i<n;i++)
        {
            if(!binary_search(B.begin(),B.end(),A[i]))
            {
                int p=lower_bound(B.begin(),B.end(),A[i])-B.begin();
                if(p<B.size())B[p]=A[i];
                else B.push_back(A[i]);
            }
        }
        cout<<B.size()<<endl;
    }
    return 0;
}
