#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y=1;
    //for(int m=10;m<=57;m++)
    //{
        y=1;
        int i=80;
        int m;cin>>m;
        while(i--)
        {
        y=(y*y+5*y+6)%m;
        cout<<y<<" ";

        }
    //}

    return 0;
}
