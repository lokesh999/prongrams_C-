#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(A[j]<0)
        {
            swap(A[i],A[j]);i++;
        }
    }
    for(int j=0;j<n;j++)
    cout<<A[j]<<" ";
    return 0;
}
