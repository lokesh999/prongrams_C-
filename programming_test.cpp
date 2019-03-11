#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream cin("input23.txt");
    //ofstream cout("output.txt");
    vector<pair<int,string> > A;

    string str;
    int tax;
    while(cin>>str>>tax)
    {
        A.push_back({tax,str});
    }
    nth_element(A.begin(),A.begin()+10,A.end());
    nth_element(A.begin(),A.end()-10,A.end());
    cout<<"first 10 lowest tax payers\n";
    for(int i=0;i<10;i++)
    {
        cout<<A[i].second<<" "<<A[i].first<<endl;
    }
    cout<<"first 10 highest tax payers\n";
    for(int i=A.size()-10;i<A.size();i++)
    {
        cout<<A[i].second<<" "<<A[i].first<<endl;
    }
    return 0;
}

