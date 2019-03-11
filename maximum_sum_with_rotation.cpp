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
        vector<int> A(n);
        for(int i=0;i<n;i++)
            cin>>A[i];
        int max=A[0],pos=0,p=n-1;
        long pro;
        for(int i=1;i<n;i++)
        {
            if(max<A[i])
            {
                max=A[i];
                pos=i;
            }
        }
        int g=pos-1;
        pro=p*A[pos];
        while((g+n)%n!=pos)
        {p--;
            pro+=p*A[(g+n)%n];
            g--;
        }
        cout<<pro<<endl;
    }
    return 0;
}
