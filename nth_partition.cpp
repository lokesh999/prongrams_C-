#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    int p;
    cin>>p;
    nth_element(A.begin(),A.end()-p,A.end());
    for(int i=0;i<n;i++)cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
