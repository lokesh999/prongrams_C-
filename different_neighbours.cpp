#include<bits/stdc++.h>
using namespace std;
int main()
{
     int A[55][55];
    int B[1][55];
    int C[2][55];
    int p=1;
    for(int i=0;i<55;i+=2)
    {
        B[0][i]=p;
        B[0][i+1]=p++;
        if(p>2)p=1;
    }
    for(int i=0;i<2;i++)
    {
        p=1;
        for(int j=0;j<55;j++)
        {
            C[i][j]=p++;
            if(p>3)p=1;
        }
    }
    for(int i=0;i<55;i++)
    {
        int g=i;
        if(g%2==0)
        {
            if((g/2)%2==0)
                p=1;
            else p=3;
        }
        else
        {
            if((g/2)%2==0)
                p=2;
            else p=4;
        }
        for(int j=0;j<55;j+=2)
        {
            A[i][j]=p;
            A[i][j+1]=p;
            p+=2;
            if(p==5) p=1;
            else if(p==6)p=2;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n>2 && m>2)
        {
            cout<<"4\n";
            for(int i=0;i<n;i++)
                {for(int j=0;j<m;j++)
                {cout<<A[i][j]<<" ";}
            cout<<endl;}
        }
        else if(n==1 || m==1)
        {
            if(n==1 && m==1)cout<<"1\n1\n";
            else if(n==2) cout<<"1\n1\n1\n";
            else if(m==2) cout<<"1\n1 1\n";
            else if(n>2)
            {
                cout<<"2\n";
                for(int i=0;i<n;i++)
                {
                   cout<<B[0][i]<<endl;
                }
            }
            else if(m>2)
            {
                cout<<"2\n";
                for(int i=0;i<m;i++)
                    cout<<B[0][i]<<" ";
                cout<<endl;
            }
        }
        else if(n==2 && m==2)
        {
            cout<<"2\n";
            cout<<"1 1\n2 2\n";
        }
        else if(n==2 || m==2)
        {
            cout<<"3\n";
            if(n>2)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<C[0][i]<<" "<<C[1][i]<<endl;
                }
            }
            else
            {
                for(int i=0;i<2;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        cout<<C[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
