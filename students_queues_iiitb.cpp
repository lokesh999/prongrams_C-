#include <bits/stdc++.h>
using namespace std;
int pos[100005];
void solve(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    pos[ar[n-1]]=1;
    int ans=1;
    for(int i=n-2;i>=0;i--){
        pos[ar[i]]=pos[ar[i]+1]+1;
        ans=max(ans,pos[ar[i]]);
    }

    cout<<n-ans;
}
int main() {
    solve();
    cout<<'\n';
    return 0;
}
