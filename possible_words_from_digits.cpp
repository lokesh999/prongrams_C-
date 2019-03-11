#include<bits/stdc++.h>
using namespace std;
vector<string> str;
void fun(int A[],int j,int n,string st )
{
    if(j<n)
    {
        for(int i=0;i<str[A[j]-2].size();i++)
        {
            string p=st;
            p+=(str[A[j]-2][i]);
            fun(A,j+1,n,p);
        }
    }
    else cout<<st<<" ";
}
int main()
{
    str.push_back("abc");
    str.push_back("def");
    str.push_back("ghi");
    str.push_back("jkl");
    str.push_back("mno");
    str.push_back("pqrs");
    str.push_back("tuv");
    str.push_back("wxyz");
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        string p;
        for(int i=0;i<n;i++)cin>>A[i];

        for(int i=0;i<str[A[0]-2].size();i++)
        {
            p="";
            fun(A,1,n, p+=str[A[0]-2][i]);
        }
        cout<<endl;
    }
}
