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
        if(n%2)cout<<"NO\n";
        else
        {
            bool f=1;
            for(int i=0;i<n/2;i++)
            {
                if(A[i]==-1 && A[i+n/2]==-1)
                {
                    A[i]=1;
                    A[i+n/2]=1;
                }
                else if(A[i] && A[i+n/2]==-1)A[i+n/2]=A[i];
                else if(A[i]==-1 && A[i+n/2])A[i]=A[i+n/2];
                else if(A[i]!=A[i+n/2])
                {
                        f=0;
                        cout<<"NO\n";
                        break;
                }
            }
            if(f)
            {
                cout<<"YES\n";
                for(int i=0;i<n;i++)
                    cout<<A[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}
