#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef string str;
typedef vector<string> vs;
typedef pair<int,int> pi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for(int i=a;i<b;i++)
int main()
{
   // ios_base::sync_with_stdio(0);
    set<int> A;
    A.insert(1);
    A.insert(2);
    A.insert(3);
    A.insert(4);
    for(set<int> :: iterator x = A.begin();x!=A.end();x++) cout<<*x<<" ";
    map<int,int> m;
    m[1]=2;
    m[2]=3;
    for(auto x:A)cout<<x<<" ";
    cout<<endl;
    for(auto x :m)cout<<x.f<<" "<<x.s<<endl;
    return 0;
}
