#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   string ch,p,q;
   cin>>n;
   vector<string> multi;
   for(int i=0;i<n;i++)
   {
       cin>>ch;
       int it= lower_bound(multi.begin(),multi.end(),ch)-multi.begin();
       p=ch;
       if(i==0) multi.push_back(ch);
    else multi.insert (it,p);
    if(multi.size()%2)
    {
        p=multi[(multi.size()-1)>>1];
        cout<<p<<".0\n";
    }
    else
    {

        p=multi[(multi.size()-1)>>1];
        q=multi[(multi.size())>>1];
        long long a=stoi(p),b=stoi(q);
        if((a+b)%2)
            cout<<(a+b)/2<<".5\n";
        else cout<<(a+b)/2<<".0\n";



    }
   }
    return 0;
}
