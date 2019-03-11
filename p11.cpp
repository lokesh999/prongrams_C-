#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[20][20];
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
            cin>>A[i][j];
    }
    long long int sum=0,m;
    for(int i=0;i<17;i++)
    {
        for(int j=0;j<17;j++)
        {
            m=A[i][j]*A[i][j+1]*A[i][j+2]*A[i][j+3];
            if(sum<m)sum=m;
            m=A[i][j]*A[i+1][j+1]*A[i+2][j+2]*A[i+3][j+3];
            if(sum<m)sum=m;
            m=A[i][j]*A[i+1][j]*A[i+2][j]*A[i+3][j];
            if(sum<m)sum=m;
        }
    }
    for(int i=19;i>2;i--)
    {
        for(int j=19;j>2;j--)
        {
            m=A[i][j]*A[i-1][j-1]*A[i-2][j-2]*A[i-3][j-3];
            if(sum<m)sum=m;
             m=A[i][j]*A[i-1][j]*A[i-2][j]*A[i-3][j];
            if(sum<m)sum=m;
            m=A[i][j]*A[i][j-1]*A[i][j-2]*A[i][j-3];
            if(sum<m)sum=m;
        }
    }


    for(int i=0;i<17;i++)
    {
        for(int j=19;j>2;j--)
        {
            m=A[i][j]*A[i+1][j-1]*A[i+2][j-2]*A[i+3][j-3];
            if(m>sum)sum=m;
        }
    }


    for(int i=19;i>2;i--)
    {
        for(int j=0;j<17;j++)
        {
            m=A[i][j]*A[i-1][j+1]*A[i-2][j+2]*A[i-3][j+3];
            if(m>sum)sum=m;
        }
    }
    cout<<sum<<endl;
    return 0;
}
