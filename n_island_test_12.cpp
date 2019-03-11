#include<bits/stdc++.h>
using namespace std;

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;


double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
    int n = int(cost.size());
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }

  for (int j = 0; j < n; j++) {

    v[j] = cost[0][j] - u[0];

    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);

  }



  // construct primal solution satisfying complementary slackness

  Lmate = VI(n, -1);

  Rmate = VI(n, -1);

  int mated = 0;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

      if (Rmate[j] != -1) continue;

      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {

        Lmate[i] = j;

        Rmate[j] = i;

        mated++;

        break;

      }

    }

  }



  VD dist(n);

  VI dad(n);

  VI seen(n);

  while (mated < n) {

    int s = 0;

    while (Lmate[s] != -1) s++;



    // initialize Dijkstra

    fill(dad.begin(), dad.end(), -1);

    fill(seen.begin(), seen.end(), 0);

    for (int k = 0; k < n; k++)

      dist[k] = cost[s][k] - u[s] - v[k];



    int j = 0;

    while (true) {



      // find closest

      j = -1;

      for (int k = 0; k < n; k++) {

        if (seen[k]) continue;

        if (j == -1 || dist[k] < dist[j]) j = k;

      }

      seen[j] = 1;



      // termination condition

      if (Rmate[j] == -1) break;



      // relax neighbors

      const int i = Rmate[j];

      for (int k = 0; k < n; k++) {

        if (seen[k]) continue;

        const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];

        if (dist[k] > new_dist) {

          dist[k] = new_dist;

          dad[k] = j;

        }

      }

    }



    // update dual variables

    for (int k = 0; k < n; k++) {

      if (k == j || !seen[k]) continue;

      const int i = Rmate[k];

      v[k] += dist[k] - dist[j];

      u[i] -= dist[k] - dist[j];

    }

    u[s] += dist[j];



    // augment along path

    while (dad[j] >= 0) {

      const int d = dad[j];

      Rmate[j] = Rmate[d];

      Lmate[Rmate[j]] = j;

      j = d;

    }

    Rmate[j] = s;

    Lmate[s] = j;



    mated++;

  }



  double value = 0;

  for (int i = 0; i < n; i++)

    value += cost[i][Lmate[i]];



  return value;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        long long int A[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                A[i][j]=1e9;
        }
        int a, b, c;
        for (int j = 0; j < m; j++) {
        cin >> a >> b >> c;
        A[a][b] = c;
        A[b][a]=c;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (A[j][k] > A[j][i] + A[i][k])
                        A[j][k] = A[j][i] + A[i][k];
                    }
                }
            }

    VVD cost;
    VD C;
    VI Lmate,Rmate;
    for(int i=1;i<=k;i++)
    {

        for(int j=n-k+1;j<=n;j++)
        {
            int p;
            p=A[i][j];
            if(p>1000)
                p=1000;
            C.push_back(p);
        }
            cost.push_back(C);
            C.clear();
    }
    cout<<MinCostMatching(cost,Lmate,Rmate)<<endl;
    }
}

