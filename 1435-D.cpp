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

/*------- sum of elements in range 1 to pos (1-Based Indexing) -------*/
int BIT[MAXN];
void update(int pos, int val, int n){
	while(pos <= n){
		BIT[pos] +=val;
		pos += (pos&-pos);
	}
}

int query(int pos){
	int res = 0;
	while(pos >= 1){
		res += BIT[pos];
		pos -= (pos&-pos);
	}
	return res;
}


void solve(){
	int n, cnt = 0, x;
	cin >> n;

	set<int, greater<int>> s;
	for(int i = 1; i <= n; ++i){
		update(i, 1, n);
		s.insert(i);
	}

	vii q;
	char ty;
	for(int i = 0; i < 2 * n; ++i){
		cin >> ty;
		if(ty == '+'){
			q.push_back({0, 0});
		}else{
			cin >> x;
			q.push_back({1, x});
		}

	}	

	vi res;
	stack<int> pos, last;
	last.push(-1);
	for(int i = 0; i < 2 * n; ++i){
		if(!q[i].first){
			cnt++;
			if(last.top() != -1)
				last.push(-1);
			pos.push(res.size());
			res.push_back(-1);
		}else{
			x = q[i].second;
			int cur = query(n) - query(x -1);
			if(cur >= cnt and cnt > 0 and x > last.top()){
				res[pos.top()] = x;
				s.erase(x);
				pos.pop();
				if(last.empty() and last.top() == -1){
					last.pop();
					if(last.top() > x){
						last.push(x);
					}
				}
				
				update(x, -1, n);
			}else{
				cout << "NO\n";
				return;
			}
			cnt--;
		}
	}

	cout << "YES\n";
	auto it = s.begin();
	for(auto itr: res){
		// if(itr == -1){
		// 	cout << (*it) << " ";
		// 	++it;
		// }else{
			cout << itr << " ";
		// }
	}
	cout << endl;

	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
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
