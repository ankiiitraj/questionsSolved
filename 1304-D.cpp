// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                               Author : Ankit Raj 
//                      Problem Name    :     Cow and Secret Message
//         		Problem Link : https://codeforces.com/contest/1304/problem/D
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector <int> adj[200005];

vector <int> BFS(int s, int dest, int n)
{
	bool visited[n +1] = {0};
	vector <int> dist(n +1, 0);
	queue <int> q;
	q.push(s); dist[s] = 0;
	visited[s] = 1;
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		for(auto itr: adj[cur])
		{
			if(visited[itr] == 0)
			{
				q.push(itr);
				dist[itr] = dist[cur] +1;
				visited[itr] = 1;
			}
		}
	}
	return dist;
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
    	int n, m, k, x, y, temp;
    	cin >> n >> m >> k;
    	for (int i = 0; i < n; ++i)
    		adj[i].clear();
    	int a[k];
    	for (int i = 0; i < k; ++i)
    	{
    		cin >> a[i];
    	}
    	for (int i = 0; i < m; ++i)
    	{
    		cin >> x >> y;
    		adj[x].pb(y);
    		adj[y].pb(x);
    	}
    	vector <int> fromOne, fromN;
  
    	fromOne =  BFS(1, n, n);
    	fromN =  BFS(n, 1, n);
    	map<int, int> mScore;

    	for(int i = 0; i < k; ++i)
    	{
    		mScore.insert({fromOne[a[i]] - fromN[a[i]], a[i]});
    	}
    	// sort(mScore.begin(), mScore.end());
    	int _max = -1000000000000, longestShortestPath = 0;

    	for(auto &itr:mScore)
    	{
    		longestShortestPath = max(longestShortestPath, _max + fromN[itr.second]);
    		_max = max(_max, fromOne[itr.second]);
    	}
    	cout << min(longestShortestPath +1, fromOne[n]) << endl;
    }
    return 0;
}