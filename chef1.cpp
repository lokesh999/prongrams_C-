#include<bits/stdc++.h>
long long mn=1e11+1,mx=0,a,b;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int> >A;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            mn=min(mn,a);
            mx=max(mx,b);
            A.push_back({a,b});
        }
        sort(A.begin(),A.end());
        for(int i=0;i<k;i++)
        {
            int p;
            cin>>p;
            if(p>=mx)cout<<"-1\n";
            else
            {
                long long low=0,high=n;
                while(low<=high)
                {
                    long long mid=(low+high)/2;
                    if(A[mid].second>p)
                    {
                        if(A[mid].first<=p)
                        {
                            cout<<"0\n";
                            break;
                        }
                        else if (mid!=0) high=mid-1;
                        else
                        {cout<<A[mid].first-1<<endl;
                        break;}
                    }
                    else
                    {if(p<A[mid+1].first)
                    {cout<<A[mid+1].first-p<<endl;
                    break;
                    }
                    else low=mid+1;

                    }
                }
            }
        }
    }
    return 0;
}
