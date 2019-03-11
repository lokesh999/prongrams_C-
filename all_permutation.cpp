#include<bits/stdc++.h>
using namespace std;
set<string> A;
set<string> ::iterator it;
void permute(string ch,int l,int j)
{
   if(l==j)A.insert(ch);
   else
   {
       for(int i=l;i<j;i++)
       {
           swap(ch[l],ch[i]);
           permute(ch,l+1,j);
           swap(ch[i],ch[l]);
       }
   }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string ch;
        cin>>ch;
        A.clear();
        permute(ch,0,ch.size());
        for(it=A.begin();it!=A.end();it++)
            cout<<*it<<" ";
        cout<<endl;

    }
    return 0;
}
