#include <bits/stdc++.h>
using namespace std;

vector<int> adj[8];

long long int arr[8], store_vals[8], max_each_vertex[8];

void depth_first_search(int u, int pred)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] != pred) 
        {
            depth_first_search(adj[u][i], u);
            if ((arr[adj[u][i]] + 1) > store_vals[u]) 
            {
                store_vals[u] = arr[adj[u][i]] + 1;
                if (store_vals[u] > arr[u])
                    swap(store_vals[u], arr[u]);
            }
        }
    }
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void calc_max_vertex(int u, int path_len, int temp)
{
    max_each_vertex[u] = (arr[u] > temp) ? arr[u] : temp;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] != path_len)
        {
            int x = (arr[adj[u][i]] + 1 == arr[u]) ? store_vals[u] : arr[u];
            x = (x > temp) ? x : temp;
            calc_max_vertex(adj[u][i], u, x + 1);
        }
    }
    // for(int i = 0; i < 10; i++)
    //     cout << max_each_vertex[i] << " ";
    // cout << endl;
}

int main()
{
  long long int n, m, x, y, v, k, max_dist = -1;
  int i;
  
  cin >> n >> m;
  for(i = 0; i < n - 1; i++)
  {
      cin >> x >> y;
      adj[x - 1].push_back(y - 1);
      adj[y - 1].push_back(x - 1);
  }
  
  depth_first_search(0, -1);
  calc_max_vertex(0, -1, 0);
  
  for(i = 0; i < n; i++)
  {
      if(max_each_vertex[i] > max_dist)
        max_dist = max_each_vertex[i];
  }
  
  for(i = 0; i < m; i++) 
  {
    cin >> v >> k;
    cout << (k-1)*max_dist + max_each_vertex[v - 1] << endl;
  }
  return 0;
}
