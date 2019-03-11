#include<bits/stdc++.h>
using namespace std;
int fun(int &g)
{
    static int a=g;
    a=a+1;
    return a;
}
int main()
{
    int g=0;
    int a=fun(g);
    g=10;
    a=fun(g);
    a=fun(g);
    cout<<a<<endl;
}
