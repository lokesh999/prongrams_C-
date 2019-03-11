#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string ch;
        cin>>ch;
        char a=ch[0];
        vector<int> A;
        for(int i=1;i<n;i++)
        {
            if(a==ch[i])
                A.push_back(i);
        }
        if(A.size()==0)cout<<ch<<endl;
        else{
            string p;
            p+=a;
            for(int i=1;i<n;i++)
            {
                bool flag=0;
                for(int j=0;j<A.size();j++)
                {
                    if(ch[A[j]+i]!=ch[i])
                    {
                        flag=1;
                    }
                }
                if(flag)break;
                else
                {
                    p+=ch[i];
                }
            }
            cout<<p<<endl;
        }

    }
    return 0;
}
