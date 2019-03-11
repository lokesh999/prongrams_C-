#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> prime(100001,1);
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=100000;i++){
        if(prime[i]){
                for(int p=2*i;p<=100000;p+=i)
                        if(prime[p])prime[p]=0;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        int c=0,b=0,a=0;
        for(int i=0;i<n;i++)cin>>A[i];
        for(int i=0;i<n;i++)
        {
            if(prime[A[i]]) c++;
            else if(A[i]%2) a++;
            else b++;
        }
         if(c==0)
        {
            if(a>b)cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else
        {
            if(a>=b)cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }
    return 0;
}
