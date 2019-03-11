#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k))
    {
        vector<vector<int> >A(n,vector<int> (k));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin>>A[i][j];
            }
            sort(A[i].begin(),A[i].end());
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cout<<A[i][j];
            }
            cout<<endl;
        }
        vector<int> C(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool f=1;
                for(int l=0;l<k;l++)
                {
                    if(A[i][l]>=A[j][l])
                    {
                        f=0;break;
                    }
                }
                if(f)C[j]++;
                cout<<C[j]<<" ";
            }
            cout<<endl;
        }
        vector<pair<int, int> > B(n);
        for(int i=0;i<n;i++)
        {
            B[i]={C[i],i};
        }
        sort(B.begin(),B.end());
        cout<<B[0].second+1<<" ";
        for(int i=1;i<n;i++)
        {
            if(B[i].first>B[i-1].first)
                cout<<B[i].second+1<<" ";
        }
        cout<<endl;

    }
    return 0;
}
