#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
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
	----------------------------------------------------------------------
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n, m;
	cin >> n >> m;
	char c;
	vector<vi> a(n +2, vi(m +2, 0)), res;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	for(int i = 1; i <= n; i += 2){
		for(int j = 1; j <= m; j += 2){
			// cout << i << " " << j << endl;
			if(j != m and i != n){
				int lt = a[i][j], rt = a[i][j +1], lb = a[i +1][j], rb = a[i +1][j +1];
				int cnt = lt + rt + lb + rb;
				if(cnt == 4){
					if((m&1 and j == m -2) or (i&1 and i == n -2)){
						a[i][j] = a[i][j +1] = a[i +1][j] = 0;
						a[i +1][j +1] = 1;
						res.push_back({i, j, i, j +1, i +1, j});
						continue;
					}else{
						res.push_back({i, j, i, j +1, i +1, j});
						res.push_back({i, j, i, j +1, i +1, j +1});
						res.push_back({i +1, j, i, j +1, i +1, j +1});
						res.push_back({i, j, i +1, j, i +1, j +1});
					}
				}else if(cnt == 3){
					vi temp;
					if(lt){
						temp.push_back(i); temp.push_back(j);
					}
					if(rt){
						temp.push_back(i); temp.push_back(j +1);	
					}
					if(lb){
						temp.push_back(i +1); temp.push_back(j);	
					}
					if(rb){
						temp.push_back(i +1); temp.push_back(j +1);	
					}
					res.push_back(temp);
				}else if(cnt == 2){
					if(lt == rb and lt){
						res.push_back({i, j +1, i +1, j, i +1, j +1});
						res.push_back({i, j, i +1, j, i, j +1});
					}else if(lb == rt and lb){
						res.push_back({i, j, i +1, j, i +1, j +1});
						res.push_back({i, j, i, j +1, i +1, j +1});
					}else if(lt == rt and lt){
						res.push_back({i +1, j, i, j +1, i +1, j +1});
						res.push_back({i, j, i +1, j, i +1, j +1});
					}else if(lb == rb and lb){
						res.push_back({i, j, i, j +1, i +1, j +1});
						res.push_back({i, j, i +1, j, i, j +1});
					}else if(lt == lb and lb){
						res.push_back({i, j +1, i +1, j, i +1, j +1});
						res.push_back({i, j, i, j +1, i +1, j +1});
					}else if(rt == rb and rb){
						res.push_back({i, j, i +1, j, i +1, j +1});
						res.push_back({i, j, i +1, j, i, j +1});
					}
				}else if(cnt == 1){
					if(lt){
						if((m&1 and j == m -2) or (i&1 and i == n -2)){
							a[i][j] = a[i][j +1] = a[i +1][j] = 0;
							a[i +1][j +1] = 1;
							res.push_back({i +1, j, i, j +1, i +1, j +1});
							res.push_back({i, j, i +1, j, i, j +1});
							continue;
						}
						res.push_back({i, j, i +1, j, i, j +1});
						res.push_back({i, j, i +1, j, i +1, j +1});
						res.push_back({i, j, i, j +1, i +1, j +1});
					}else if(rt){
						if((m&1 and j == m -2) or (i&1 and i == n -2)){
							a[i][j] = a[i][j +1] = a[i +1][j] = 0;
							a[i +1][j +1] = 1;
							res.push_back({i, j, i +1, j, i +1, j +1});
							res.push_back({i, j, i +1, j, i, j +1});
							continue;
						}
						res.push_back({i, j, i, j +1, i +1, j +1});
						res.push_back({i, j +1, i +1, j, i +1, j +1});
						res.push_back({i, j, i +1, j, i, j +1});
					}else if(lb){
						if((m&1 and j == m -2) or (i&1 and i == n -2)){
							a[i][j] = a[i][j +1] = a[i +1][j] = 0;
							a[i +1][j +1] = 1;
							res.push_back({i, j, i, j +1, i +1, j +1});
							res.push_back({i, j, i +1, j, i, j +1});
							continue;
						}
						res.push_back({i, j, i +1, j, i +1, j +1});
						res.push_back({i, j +1, i +1, j, i +1, j +1});
						res.push_back({i, j, i +1, j, i, j +1});
					}else{
						if((m&1 and j == m -2) or (i&1 and i == n -2)){
							continue;
						}
						res.push_back({i +1, j +1, i +1, j, i, j +1});
						res.push_back({i, j, i +1, j, i +1, j +1});
						res.push_back({i, j, i, j +1, i +1, j +1});
					}
				}
				a[i][j] = a[i +1][j] = a[i][j +1] = a[i +1][j +1] = 0;
			}else{
				if(i == n){
					i--;
					j -= 2;
				}else if(j == m){
					j -= 3;
				}
			}
			// for(int k = 1; k <= n; ++k){
			// 	for(int l = 1; l <= m; ++l){
			// 		cout << a[k][l] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
		}
	}

	cout << res.size() << endl;
	for(auto itr: res){
		for(auto it: itr){
			cout << it << " ";
		}
		cout << endl;
	}

	return;
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
