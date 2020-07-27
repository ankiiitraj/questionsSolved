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
const int MAXN = 1000005; // 1e6 +5

void solve(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	vi ans;
	int cnt = 0, left = 0, right = n -1, idx = n -1;

	while(idx >= 0){
		if(!(cnt&1)){
			if(a[right] == b[idx]){
				right--;
				idx--;
			}else if(a[left] == b[idx]){
				ans.push_back(1);
				// a[left] = a[left] == '1' ? '0' : '1';
				ans.push_back(idx +1);
				cnt++;
				left++;
				idx--;
			}else{
				ans.push_back(idx +1);
				cnt++;
				left++;
				idx--;
			}
		}else{
			if(a[left] != b[idx]){
				left++;
				idx--;
			}else if(a[right] != b[idx]){
				ans.push_back(1);
				// a[right] = a[right] == '1' ? '0' : '1';
				ans.push_back(idx +1);
				cnt++;
				right--;
				idx--;
			}else{
				ans.push_back(idx +1);
				cnt++;
				right--;
				idx--;
			}
		}
	}
	cout << ans.size() << " ";
	for(auto itr: ans)
		cout << itr << " ";
	cout << endl;
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
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
	