#include<bits/stdc++.h>
using namespace std;
vector<int> A(1000000,1);
void ss()
{
    A[0]=0;
    A[1]=0;
    for(int i=2;i*i<=1000000;i++)
    {
        if(A[i])
        {
            for(int j=2*i;j<=1000000;j+=i)
                if(A[j])A[j]=0;
        }
    }
    for(int i=1;i<=100;i++)
    {
        A[i]+=A[i-1];
    }
}
int main()
{
    ss();
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        cout<<A[n]<<endl;
    }
    return 0;
}
