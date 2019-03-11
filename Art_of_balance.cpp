#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string ch;
       cin>>ch;
       int l=0;
       vector<int> A(26,0),B(26);
       for(int i=0;i<ch.size();i++)
       {
           if(A[ch[i]-'A']==0)l++;
           A[ch[i]-'A']++;
       }
       sort(A.begin(),A.end(),greater<int>());
       B[0]=A[0];
       for(int i=1;i<26;i++)
        B[i]=B[i-1]+A[i];

       int p=0,sum= ch.size()-B[0],n=ch.size();
       for(int i=2;i<=26 && i<=n && i<=n;i++)
       {
           p=0;
           int y;
           if(n%i==0)
           {
            y=n/i;

           if(i<=l)

           {
               p=n-B[i-1];
               for(int j=0;j<i-1;j++)
            {if(A[j]>y)p+=A[j]-y;
}}
           else{ p=0;
           for(int j=0;j<l;j++)
            {if(A[j]>y)p+=A[j]-y;
}}
           if(sum>p) sum=p;
           //cout<<sum<<endl;
           }
       }
       cout<<sum<<endl;
   }
    return 0;
}
