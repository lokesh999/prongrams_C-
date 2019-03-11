#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> last_electrified_pole(n);
    int last=-1,p,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        if(p==1) last=i;
        last_electrified_pole[i]=last;
    }
    for(int i=0;i<n;)
    {
        int last_pole = last_electrified_pole[min(i+k-1,n-1)];
        if(last_pole==-1 || last_pole+k<=i)
        {
            cout<<"-1"<<endl;
            return 0;
        }
         i=last_pole+k;
         ans++;
    }
    cout<<ans<<endl;
    return 0;
}
