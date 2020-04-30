#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/
vi adj[100005];

int diameter[10001]; 
  
// The Function to do bfs traversal. 
// It uses iterative approach to do bfs 
// bfsUtil() 
int bfs(int init, vector<int> arr[], int n) 
{ 
    queue<int> q; 
    q.push(init); 
  
    int visited[n + 1]; 
    for (int i = 0; i <= n; i++) { 
        visited[i] = 0; 
        diameter[i] = 0; 
    } 
  
    q.push(init); 
  
    visited[init] = 1; 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        for (int i = 0; i < arr[u].size(); i++) { 
            if (visited[arr[u][i]] == 0) { 
                visited[arr[u][i]] = 1; 
  
                diameter[arr[u][i]] += diameter[u] + 1; 
                q.push(arr[u][i]); 
            } 
        } 
    } 
  
    return int(max_element(diameter + 1, diameter + n + 1) - diameter); 
} 
  
int findDiameter(vector<int> arr[], int n) 
{ 
    int init = bfs(1, arr, n); 
    int val = bfs(init, arr, n); 
    return diameter[val]; 
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
		int n, x, y;
		cin >> n;
		for(int i = 0; i <= n; ++i){
			adj[i].clear();
		}
		for(int i = 0; i < n; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}



		cout <<  << " " << n - 1 << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	