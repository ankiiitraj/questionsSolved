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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
int n, k;
vector <int> a;
set<vi> ans;

void recurse(int pos, int cur_sum, vector<int> res){
	if(pos == n){
		if(cur_sum == k){
			sort(all(res));
			ans.insert(res);
		}
		return;
	}
	recurse(pos +1, cur_sum, res);
	res.push_back(a[pos]);
	recurse(pos +1, cur_sum + a[pos], res);
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		cin >> n >> k;
		vector <int> res;
		a.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		recurse(0, 0, res);

		for(auto itr: ans){
			for(auto it: itr)
				cout << it << " ";
			cout << endl;
		}

	}
}


//Author : Ankit Raj
//Problem Link : https://www.hackerearth.com/problem/algorithm/subset-sum-8

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
	