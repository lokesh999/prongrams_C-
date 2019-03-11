#include<bits/stdc++.h>
using namespace std;
int n;
int c;
void count_total_number_of_ways(int y)
{
    static vector<bool> r1(n,0),r2(n,0),r3(n,0);
    if(y==n)
    {
        c++;return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(r1[i]||r2[y+i]||r3[i-y+n-1])continue;
            r1[i]=r2[y+i]=r3[i-y+n-1]=1;
            count_total_number_of_ways(y+1);
            r1[i]=r2[y+i]=r3[i-y+n-1]=0;
        }
    }
}

int main()
{
    c=0;
    cin>>n;
    count_total_number_of_ways(0);
    cout<<c<<endl;
    return 0;
}
