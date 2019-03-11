#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter number of stores\n";
    int n;
    cin>>n;
    int c;
    cout<<"Enter the cost of transportation\n";
    cin>>c;
    int A[n],B[n];
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<n;i++)cin>>B[i];
    for(int i=1;i<n;i++)
    {
        A[i]=A[i]+max(A[i-1],B[i-1]-c);
        B[i]=B[i]+max(B[i-1],A[i-1]-c);
    }
    cout<<"enter the ith day for profit\n";
    cin>>n;
    cout<<A[n-1]<<" "<<B[n-1]<<endl;

    return 0;
}
