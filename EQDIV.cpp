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
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5
vi global_res;
void rec(const vi &sq, int pos, int n, int sum, int tot_sum, vi &res){
	if(pos == n){
		if(sum == tot_sum){
			global_res = res;
		}
		return;
	}
	rec(sq, pos +1, n, sum, tot_sum, res);
	res.push_back(pos);
	rec(sq, pos +1, n, sum + sq[pos], tot_sum, res);
	res.pop_back();
}

void rec(const vi &sq, int pos, int n, int sum, int tot_sum, vi &res, int *min){
	if(pos == n){
		if(abs(sum - (tot_sum - sum)) < *min){
			global_res = res;
			*min = abs(sum - (tot_sum - sum));
		}
		return;
	}
	rec(sq, pos +1, n, sum, tot_sum, res, min);
	res.push_back(pos);
	rec(sq, pos +1, n, sum + sq[pos], tot_sum, res, min);
	res.pop_back();
}

void solve1(){
	int n, cnt = 0;
	cin >> n;
	// if(k == 2){
	// 	vi a;
	// 	int sum = 0;
	// 	for(int j = 1; j <= n; ++j){
	// 		a.push_back(j*j);
	// 		sum += j*j;
	// 		cout << rec(a, 0, j, 0, sum) << " " << sum << endl;
	// 	}
	// }else{
		string s;
		for(int i = n; i >= 1; --i){
			if(cnt == 0){
				s += '1';
			}else if(cnt == 1){
				s += '0';
			}else if(cnt == 2){
				s += '0';
			}else{
				cnt = -1;
				s += '1';
			}
			cnt++;
		}
		if(n%4 == 3 or n%4 == 0){
			cout << "0\n";
		}else{
			cout << "1\n";
		}
		reverse(all(s));
		cout << s << endl;
	// }
	return;
}

void solve2(){
	int n, total = 0;
	cin >> n;

	if(n <= 10){
		global_res.clear();
		vi sq, res;
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			sq.push_back(i * i);
			sum += i * i;
		}
		int _min = 1e18;
		rec(sq, 0, n, 0, sum, res, &_min);
		cout << _min << endl;
		vi visited(n +1, 0);
		for(const auto itr: global_res){
			visited[itr +1] = 1;
		}

		for(int i = 1; i <= n; ++i){
			cout << visited[i];
		}
		cout << endl;
		return;
	}

	vi sq, a, b, upto_10;
	sq.push_back(0);
	for(int i = 1; i <= n; ++i){
		sq.push_back(i * i);
		if(i <= 10)
			upto_10.push_back(i * i);
		total += i * i;
	}

	int idx = n, a_sum = 0, b_sum = 0;
	while(idx > 10){
		if(a_sum > b_sum){
			b.push_back(idx);
			b_sum += sq[idx];
		}else{
			a.push_back(idx);
			a_sum += sq[idx];
		}
		idx--;
	}
	int diff = a_sum - b_sum;
	if(diff < 0){
		vi temp = a;
		a = b;
		b = temp;
	}

	int req = (385LL - abs(diff))/2;
	vi remaining;
	global_res.clear();
	rec(upto_10, 0, 10, 0, req, remaining);
	vi visited(n +1, 0);
	if(total&1){
		cout << "1\n";
	}else{
		cout << "0\n";
	}
	for(auto itr: a){
		visited[itr] = 1;
	}
	for(auto itr: global_res){
		visited[itr +1] = 1;
	}
	int sum_1 = 0, sum_2 = 0;
	for(int i = 1; i <= n; ++i){
		cout << visited[i];
		if(visited[i])
			sum_1 += i*i;
		else
			sum_2 += i*i;
	}
	assert(abs(sum_1 - sum_2) <= 1);
	cout << endl;
}

void solve3(){
	int n, total = 0, limit = 30, limit_sum = 0;
	cin >> n;

	if(n <= limit){
		global_res.clear();
		vi sq, res;
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			sq.push_back(i * i);
			sum += i * i;
		}
		int _min = 1e18;
		rec(sq, 0, n, 0, sum, res, &_min);
		cout << _min << endl;
		vi visited(n +1, 0);
		for(const auto itr: global_res){
			visited[itr +1] = 1;
		}

		for(int i = 1; i <= n; ++i){
			cout << visited[i];
		}
		cout << endl;
		return;
	}

	vi sq, a, b, upto_10;
	sq.push_back(0);
	for(int i = 1; i <= n; ++i){
		sq.push_back(i * i * i);
		if(i <= limit)
			upto_10.push_back(i * i * i), limit_sum += i * i * i;
		total += i * i * i;
	}

	int idx = n, a_sum = 0, b_sum = 0;
	while(idx > limit){
		if(a_sum > b_sum){
			b.push_back(idx);
			b_sum += sq[idx];
		}else{
			a.push_back(idx);
			a_sum += sq[idx];
		}
		idx--;
	}
	int diff = a_sum - b_sum;
	if(diff < 0){
		vi temp = a;
		a = b;
		b = temp;
	}

	int req = (limit_sum - abs(diff))/2;
	vi remaining;
	global_res.clear();
	rec(upto_10, 0, limit, 0, req, remaining);
	vi visited(n +1, 0);
	if(total&1){
		cout << "1\n";
	}else{
		cout << "0\n";
	}
	for(auto itr: a){
		visited[itr] = 1;
	}
	for(auto itr: global_res){
		visited[itr +1] = 1;
	}
	int sum_1 = 0, sum_2 = 0;
	for(int i = 1; i <= n; ++i){
		cout << visited[i];
		if(visited[i])
			sum_1 += i*i;
		else
			sum_2 += i*i;
	}
	assert(abs(sum_1 - sum_2) <= 1);
	cout << endl;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t, k; cin >> k >> t; while(t--){
		if(k == 1)
			solve1();
		else if(k == 2)
			solve2();
		else
			solve3();
	}
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
	