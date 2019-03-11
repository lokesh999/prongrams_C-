#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream cin("input23.txt");
    //ofstream cout("output.txt");
    pair<int,string>  q,r;
    priority_queue<pair <int,string> > max_heap;
    priority_queue<pair<int,string>, vector<pair<int,string> >, greater<pair<int,string> > >min_heap;

    string str;
    int tax;
    int i=0;
    while(cin>>str>>tax)
    {
        if(i<10)
        {
            max_heap.push({tax,str});
            min_heap.push({tax,str});
            i++;
        }
        else
        {
            q=max_heap.top();
            r=min_heap.top();
            if(tax<q.first)
            {
                max_heap.pop();
                max_heap.push({tax,str});
            }
            if(tax>r.first)
            {
                min_heap.pop();
                min_heap.push({tax,str});
            }
        }
    }
    cout<<"first 10 lowest tax payers\n";
   while(!max_heap.empty()){
        q=max_heap.top();
        max_heap.pop();
        cout<<q.second <<" "<<q.first<<endl;
    }
    cout<<"first 10 highest tax payers\n";
     while(!min_heap.empty()){
        r=min_heap.top();
        min_heap.pop();
        cout<<r.second <<" "<<r.first<<endl;
    }
    return 0;
}
