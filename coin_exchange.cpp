#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"enter the number of coins\n";
        int n;
        cin>>n;
        int A[n];
        cout<<"Enter the denomination (first must be 1)\n";
        for(int i=0;i<n;i++)
        cin>>A[i];
        cout<<"Enter the amount to pay\n";
        int m;
        cin>>m;
        int B[m+1][n];
        for(int i=0;i<n;i++){B[0][i]=0;B[1][i]=1;}
        for(int i=1;i<m+1;i++)B[i][0]=i;
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i>=A[j]&& B[i][j-1]> 1+B[i-A[j]][j])
                    B[i][j]=1+B[i-A[j]][j];
                else B[i][j]=B[i][j-1];
            }
        }
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<B[i][j]<<" ";
            cout<<endl;
        }
        int i=n-1;
        int j=m;

        while(i>=0)
        {
            if(i==0&&B[j][i])
            {cout<<B[j][i]<<" by 1 rupee coins\n"; break;}
            if(B[j][i]== 1+B[j-A[i]][i])
            {
                cout<<A[i]<<" ";
                j-=A[i];
            }
            else i--;
        }


        /*
        int B[m+1];
        for(int i=0;i<=m;i++)B[i]=i;
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if( i>= A[j] && B[i]> 1+ B[i-A[j]])
                    B[i]=1+B[i-A[j]];
            }
        }
        for(int i=0;i<=m;i++)
        {
            cout<<B[i]<<" ";
        }
        cout<<"back tracking\n";
        int j=m;
        int i=n-1;
        while(i>=0)
        {
            if(i==0 && j)
            {
                cout<<j<<" one rupee coins ";
                break;
            }
            else if(B[j]==1+B[j-A[i]])
            {
                cout<<A[i]<<" " ;
                j-=A[i];
            }
            else i--;
        }*/

    }
    return 0;
}
