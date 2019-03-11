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
        for(int i=0;i<ch.size();i++)
        {
            int p=ch[i]-'0';
            if(p<5)
                ch[i]=9-p+'0';
        }
        cout<<ch<<endl;
    }
    return 0;
}
