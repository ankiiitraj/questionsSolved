#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
  Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 100005; // 1e5 +5


int n, q, x, y, r, w, lg;
vii adj[MAXN];
vi dist(MAXN), depth(MAXN);
vector<vi> up;

int lift(int u, int d, vector<vi> &up){
  if(d == 0 or u == -1){
    return u;
  }
 
  for(int i = lg; i >= 0; --i){
    if(d >= (1 << i)){
      return lift(up[u][i], d - (1<<i), up);
    }
  }
  return 0;
}
 
void init_binary_lifting(int u, int par, int d){
  up[u][0] = par;
  for(int i = 1; i <= lg; ++i){
    if(up[u][i -1] != -1){
      up[u][i] = up[up[u][i -1]][i -1];
    }else{
      up[u][i] = -1;
    }
  }
  depth[u] = d;
  for(auto itr: adj[u]){
    if(itr.first != par){
      init_binary_lifting(itr.first, u, d +1);
    }
  }
}
 
int lca(int u, int v){
  if(depth[u] != depth[v]){
    if(depth[u] > depth[v]){
      u = lift(u, depth[u] - depth[v], up);
    }else{
      v = lift(v, depth[v] - depth[u], up);
    }
  }

  if(u == v)
    return u;
 
  for(int i = lg; i >= 0; --i){
    if(up[u][i] != up[v][i]){
      u = up[u][i];
      v = up[v][i];
    } 
  }
  return up[u][0];
}
 
void dfs(int s, int par, int d){
  dist[s] = d;
  for(auto itr: adj[s]){
    if(itr.first != par){
      dfs(itr.first, s, d + itr.second);
    }
  }
}
 
void solve(){
  scanf("%lld%lld%lld", &n, &q, &r);
  lg = ceil(log2(n));
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  for(int i = 0; i < n -1; ++i){
    scanf("%lld%lld%lld", &x, &y, &w);
    adj[y].push_back({x, w});
    adj[x].push_back({y, w});
}

  dist = vi(n +1, 0);
  dfs(r, -1, 0);

  depth = vi(n +1, 0);
  up = vector<vi>(n +1, vi(lg +1, 0));
  
  init_binary_lifting(r, 0, 0);
  
  while(q--){
    scanf("%lld%lld", &x, &y);

    int res = dist[x] + dist[y] - 2 * dist[lca(x, y)];
    printf("%lld\n", res);
  }
  
}
 
signed main()
{
  faster;
#ifndef ONLINE_JUDGE
  freopen("ip.txt", "r", stdin);
  freopen("op.txt", "w", stdout);
#endif
  int t; scanf("%lld", &t); while(t--)
    solve();
  return 0;
}
 
 
//Author : Ankit Raj
//Problem Link :
 
/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/