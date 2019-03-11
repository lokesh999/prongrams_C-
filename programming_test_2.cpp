#include<bits/stdc++.h>

using namespace std;

void Kuhn_InitializeLabeling(vector<vector<int>> & w, vector<int>   & lx, vector<int>   & ly)
{
 int size = w.size();
 for(int i = 0; i < size; i++)
 {
  ly.push_back(0);
  int max = 0;
  for(int j = 0; j < size; j++)
  {
   if(w[i][j] > max)
   {
    max = w[i][j];
   }
  }
  lx.push_back(max);
 }
}


int Kuhn_InitialMatching(vector<vector<int>> & w, vector<int>   & lx, vector<int>   & ly,vector<int>   & M,vector<bool>  & xfree)
{
 int matchCount = 0;
 int size = w.size();
 for(int i = 0; i < size; i++)
 {
  bool matched = false;
  for(int j = size - 1; j >= 0; j--)
  {
   if(lx[j] + ly[i] == w[j][i])
   {
    M.push_back(j);
    matched = true;
    xfree[j] = false;
    matchCount++;
    break;
   }
  }
  if(!matched)
  {
   M.push_back(-1);
  }
 }


 return matchCount;
}


vector<int> Kuhn(vector<vector<int>> w)
{
 int matchCount;
 int size = w.size();
 vector<int> lx, ly, M;
 Kuhn_InitializeLabeling(w, lx, ly);
 vector<bool> xfree(size, true);
 matchCount = Kuhn_InitialMatching(w, lx, ly, M, xfree);


 while(matchCount < size)
 {
  int u;
  vector<int> S;
  vector<int> T;
  vector<bool> inS(size, false);
  vector<bool> inT(size, false);
  for(int i = 0; i < size; i++)
  {
   if(xfree[i])
    u = i;
  }
  S.push_back(u);
  inS[u] = true;


  while(1)
  {
   int y;
   bool found = false;
   for(int i = 0; i < S.size() && !found; i++)
   {
    int v = S[i];
    for(int j = 0; j < size; j++)
    {
     if(lx[v] + ly[j] == w[v][j] && !inT[j])
     {
      y = j;
      found = true;
      break;
     }
    }
   }
   if(found)
   {
    if(M[y] < 0) // if y is not matched
    {
     //then augment M by adding (u,y)
     T.push_back(y);
     for(int i = 0; i < T.size(); i++)
     {
      M[T[i]] = S[i];
     }
     xfree[u] = false;
     matchCount++;
     break;
    }
    else
    {
     int z = M[y]; // y is matched to z
     //extend alternating tree
     T.push_back(y);
     S.push_back(z);
     inS[z] = true;
     inT[y] = true;
    }
   }
   else
   {
    int al = -1;
    for(int i = 0; i < inT.size(); i++)
    {
     if(!inT[i])
     {
      for(int j = 0; j < S.size(); j++)
      {
       int x = S[j];
       int val = lx[x] + ly[i] - w[x][i];
       if(val < al || al == -1)
       {
        al = val;
       }
      }
     }
    }
    for(int i = 0; i < size; i++)
    {
     if(inS[i])
      lx[i] -= al;
     if(inT[i])
      ly[i] += al;
    }
   }
  }
 }


 return M;
}


void Run1()
{
    int n,m;
    cin>>n>>m;
 vector<vector<int>> w(n,vector<int> (m));
 long int p=0;
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         cin>>w[i][j];

     /*
        cin>>w[i][j];
        if(p>w[i][j])p=w[i][j];

   */  }
 }


 vector<int> M = Kuhn(w);
 int weight = 0;
 for(int i = 0; i < M.size(); i++)
 {
  int x = M[i];
  int y = i;
  weight += (w[x][y]);

 }
 //if(!f)weight=*weight;
 printf("\nWeight: %d\n", weight);
 //printf("\n--------------------\n");
}



int main ()
{
 Run1();
}
