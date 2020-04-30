#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 100005; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
void deleteEdge(vector<int> adj[], int u, int v){
	adj[u].erase(find(all(adj[u]), v));
	adj[v].erase(find(all(adj[v]), u));
}
  
// function to check whether a graph is bipartite or not 
bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 
  
        // if vertex u is not explored before 
        if (visited[u] == false) { 
  
            // mark present vertic as visited 
            visited[u] = true; 
  
            // mark its color opposite to its parent 
            color[u] = !color[v]; 
  
            // if the subtree rooted at vertex v is not bipartite 
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        // if two adjacent are colored with same color then 
        // the graph is not bipartite 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n, q, ty, u, v;
		cin >> n >> q;
		vi adj[n +1]; 
		while(q--){
			cin >> ty >> u >> v;
			if(ty == 1){
				addEdge(adj, u, v);
			}else{
				addEdge(adj, u, v);vector<bool> visited(N + 1); 
  
			    // to color the vertices 
			    // of graph with 2 color 
			    vector<int> color(N + 1); visited[1] = true; 
			  
			    // marking the source node with a color 
			    color[1] = 0; 
			  
			    cout << (isBipartite(adj, u, visited, color) ? "Yes" : "No") << endl;
			    deleteEdge(adj, u, v);
			}
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
