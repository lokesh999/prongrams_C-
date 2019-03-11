#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    long long maximum,result= -1e10;
    for(int i=0;i<n;i++)
    {
        maximum=A[i];
        int j=i+1;
        for(;j<n;j++)
        {
            if(maximum<maximum*A[j]) {maximum=maximum*A[j];
            if(A[j]==0) break;}
            else break;
        }
        i=j;
        if(result<maximum) result = maximum;
    }
    cout << result<<endl;
    return 0;
}
