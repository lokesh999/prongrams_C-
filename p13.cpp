#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char A[n][50];
    for(int i=0;i<n;i++)
        for(int j=0;j<50;j++)cin>>A[i][j];
    int sum=0;
    for(int i=49;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            sum+=A[j][i]-'0';
        }
        A[n-1][i]=sum%10+'0';
        sum=sum/10;
    }
    int l=0;
    while(sum)
    {
        cout<<sum%10;
        sum=sum/10;
        l++;
        if(l==10)break;
    }
    if(l<10)
    {
        for(int i=0;i<50;i++)
        {
            cout<<A[n-1][i]-'0';
            l++;
            if(l==10)break;
        }
    }
    return 0;
}
