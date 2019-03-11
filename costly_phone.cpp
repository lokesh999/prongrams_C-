#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A[10];
        for(int i=0;i<10;i++)
        {
            cin>>A[i];
        }
        bool flag=0;
        while(1)
        {
            flag=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                int k=(i+j)%10;
                if(A[k]>A[i]+A[j])
                {
                    A[k]=A[i]+A[j];
                    flag=1;
                }
            }
        }
        if(flag==0) break;
        }
        int n;
        cin>>n;
        int c=0;
        string p;
        cin>>p;
        for(int i=0;i<n;i++)
        {
           c+= A[p[i]-'0'];
        }
        cout<<c<<endl;
    }
    return 0;
}
