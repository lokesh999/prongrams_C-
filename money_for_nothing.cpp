#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define MAX 500005
#define INF 1e18
#define fi first
#define se second

vector<pair<lli,lli> > prod,cons;
vector<lli> dp(MAX,-1);

void prune()
{
    sort(prod.begin(),prod.end());
    sort(cons.begin(),cons.end());
    reverse(cons.begin(),cons.end());
    vector<pair<lli,lli> > temp;
    for(auto p: prod)
    {
        if(!temp.empty()&& temp.back().se<=p.se)continue;
        temp.push_back(p);
    }
    prod=temp;
    temp.clear();
    for(auto c:cons)
    {
        if(!temp.empty()&& temp.back().se>=c.se)continue;
        temp.push_back(c);
    }
    cons=temp;
    reverse(cons.begin(),cons.end());
}
void ComputeDP(int lcons,int rcons,int lprod, int rprod)
{
    if(lcons==rcons) return ;
    int mcons =(lcons+rcons)/2;
    auto c = cons[mcons];
    int mprod =-1;
    dp[mcons]=0;
    for(int i=lprod;i<rprod;i++)
    {
        auto p=prod[i];
        if(p.fi>c.fi || p.se>c.se) continue;
        lli val = (c.se-p.se)*(c.fi-p.fi);
        if(val>dp[mcons])
        {
            dp[mcons]=val;
            mprod =i;
        }
    }

    if(mprod == -1)
    {
        mprod = rprod-1;
        while(mprod>lprod && prod[mprod].fi >cons[mcons].fi)mprod--;
    }
    ComputeDP(lcons,mcons,lprod,mprod+1);
    ComputeDP(mcons+1,rcons,mprod,rprod);
}
int main()
{
    int n,m;
    cin>>n>>m;
    prod.resize(n);
    cons.resize(m);
    for(int i=0;i<n;i++)
        cin>>prod[i].fi >> prod[i].se;
    for(int i=0;i<m;i++)
        cin>>cons[i].fi>>cons[i].se;
    prune();
    ComputeDP(0,cons.size(),0,prod.size());
    lli ans=0;
    for(int i=0;i<m;i++)ans=max(ans,dp[i]);

    cout<<ans<<endl;
}
