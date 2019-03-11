#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A(305,0);
    A[0]=1;
    int sum=0,c=0;
    for(int i=0;i<1000;i++)
    {
        int j=0;
        while(j<305)
        {
            sum+=A[j]*2;
            A[j]=sum%10;
            sum=sum/10;
            j++;
        }
        if(sum){A[j]=sum;sum=0;}
    }
    for(int i=0;i<305;i++)
    {cout<<A[i];c+=A[i];
    }

    cout<<endl<<c;
    return 0;
}

