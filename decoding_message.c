#include <iostream>
using namespace std;

int main() {
	//code
	return 0;
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string ch;
	    cin>>ch;
	    int A[n];
	    for(int i=0;i<n;i++)A[i]=ch[i]-48;
	    int a=1,b,c;
	    if(A[0]*10+A[1]<=26){
	        b=2;
	    }
	    else b=1;
	    for(int i=2;i<n;i++)
	    {
	        if(A[i-1]*10+A[i]<27)
	        c=a+b;
	        a=b;
	        b=c;
	    }
	    cout<<c;
	}
}
