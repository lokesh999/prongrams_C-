#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=1,b=2,c;
    long sum=2;
    while(a+b<=4000000)
    {
        c=a+b;
        if(c%2==0)sum+=c;
        a=b;b=c;
    }
    cout<<sum<<endl;
    return 0;
}
