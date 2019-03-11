#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,e,f,sum=0;
    for(int i=100;i<1000;i++)
    {
        for(int j=100;j<1000;j++)
        {
            c=i*j;
            int p=0,q=c;
            while(c)
            {
                p=p*10;
                p+=c%10;
                c=c/10;
            }
            if(p==q)
            {
                if(sum<p){sum=p;
                e=i;
                f=j;}
            }
        }
    }
    cout<<e<<" "<<f<<" "<<sum;
    return 0;
}
