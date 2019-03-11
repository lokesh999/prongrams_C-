#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,v,u;
    for(int i=1;i*i<=500;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(i*i+i*j==500)
            {
                v=i;u=j;
            }
        }
    }
    a=v*v-u*u;
    b=2*u*v;
    c=u*u+v*v;
    cout<<a <<" "<<b<<" "<<c<<endl;
    cout<<a*b*c<<endl;
    return 0;
}
