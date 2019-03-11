#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string ch;
	    cin>>ch;
	    int A[n+1];
	    for(int i=1;i<=n;i++)A[i]=ch[i-1]-48;
	    vector<int> result(n+1,0);
	    result[0]=1;
	    if(n>0 && A[1])result[1]=1;
	    else {
            cout<<"0\n";continue;
	    }
	    for(int i=2;i<=n;i++)
        {
            if(A[i]+A[i-1]*10<27 && A[i]+A[i-1]*10>0 && A[i-1]==0)
                result[i]=result[i-1];
            else if(A[i]+A[i-1]*10<27 && A[i]+A[i-1]*10>0 && A[i]!=0)
                result[i]=result[i-1]+result[i-2];
            else if(A[i]+A[i-1]*10<27&&   A[i]+A[i-1]*10>0&& A[i]==0)
                result[i]=result[i-2] ;
            else if(A[i]+A[i-1]*10>26 && A[i]>0)
                result[i]=result[i-1];
            else {
                result[n]=0;
                break;
            }

        }
        for(int i=0;i<=n;i++)cout<<result[i]<<" ";cout<<endl;
        cout<<result[n]<<endl;
	}
	return 0;
}
