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


signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif

	int n, a;
	cin >> n;
	map<int, int> m_1, m_2;
	for(int i = 0; i < n; ++i){
		cin >> a;
		m_1[a]++;
	}
	for(auto itr: m_1){
		m_2[itr.second]++;
	}

	int q;
	cin >> q;
	char type;
	while(q--){
		cin >> type >> a;
		if(type == '+'){
			if(m_1[a] > 0){
				m_2[m_1[a]]--;
			}
			m_2[m_1[a] +1]++;
			m_1[a]++;
		}else{
			if(m_1[a] > 0){
				if(m_1[a] -1 > 0) 
					m_2[m_1[a] -1]++;
				m_2[m_1[a]]--;
				m_1[a]--;
			}
		}
		int flag = 0;
		for(auto itr = m_2.rbegin(); itr != m_2.rend(); ++itr){
			if(itr->first >= 8 and itr->second > 0){
				flag = 1;
				cout << "YES\n";
				break;
			}else if(itr->first == 7 and itr->second > 0){
				if(itr->second > 1){
					cout << "YES\n";
					flag = 1;
					break;
				}
				for(int j = 2; j <= 6; ++j){
					if(m_2[j] > 0){
						flag = 1;
						cout << "YES\n";
						break;
					}
				}
				if(flag){
					break;
				}
			}else if(itr->first == 6 and itr->second > 0){
				if(itr->second > 1){
					cout << "YES\n";
					flag = 1;
					break;
				}
				for(int j = 2; j < 6; ++j){
					if(m_2[j] > 0){
						flag = 1;
						cout << "YES\n";
						break;
					}
				}
				if(flag){
					break;
				}
			}else if(itr->first == 5 and itr->second > 0){
				if(itr->second > 1){
					cout << "YES\n";
					flag = 1;
					break;
				}
				if(m_2[2] > 1 or m_2[3] > 1 or m_2[4] > 0 or (m_2[2] == 1 and m_2[3] == 1)){
					cout << "YES\n";
					flag = 1;
					break;
				}
			}else if(itr->first == 4 and itr->second > 0){
				if(itr->second > 1){
					cout << "YES\n";
					flag = 1;
					break;
				}
				if(m_2[2] > 1 or m_2[3] > 1 or (m_2[2] == 1 and m_2[3] == 1)){
					cout << "YES\n";
					flag = 1;
					break;
				}
			}
		}
		if(!flag)
			cout << "NO\n";


		// debug(m_1, m_2);
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
		