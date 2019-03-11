#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,v,x;
        cin>>n>>x;
        vector<pair<int,int> > A(n);
        for(int i=0;i<n;i++)
        {
            cin>>A[i].first;
        }
        for(int i=0;i<n;i++)
            cin>>A[i].second;
        sort(A.begin(),A.end());
        int B[n][x+1];
        for(int j=0;j<=x;j++)
        {

            B[0][j]=0;
            if(A[0].first<=j)
                B[0][j]=A[0].second;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=x;j++)
            {
                B[i][j]=0;
                if(A[i].first<=j)
                {
                    B[i][j]=max(B[i-1][j],B[i-1][j-A[i].first]+A[i].second);
                }
                 else B[i][j]=B[i-1][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=x;j++)
                cout<<B[i][j]<<" ";
            cout<<endl;
        }
        cout<<"objects used\n";
        int p=n-1,q=x;
        while(B[p][q])
        {
            if(B[p-1][q]!=B[p][q])
            {
                cout<<A[p].first<<" ";
                q=q-A[p].first;
            }
            p--;
        }
    }
    return 0;
}
