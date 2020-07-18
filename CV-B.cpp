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

void solve(){
	int n, res = 0;
	cin >> n;
	vi a(n), even_pos, odd_pos, significant_bit_count(10, 0);
	scnarr(a, n);
	int i = 0;
	for(auto itr: a){
		int temp = itr;
		si s;
		while(temp){
			s.insert(temp%10);
			temp /= 10;
		}
		int greatest = *s.rbegin(), smallest = *s.begin();
		int num = greatest*11 + smallest*7;
		if(num >= 100)
			num %= 100;
		if(i&1)
			odd_pos.push_back(num);
		else
			even_pos.push_back(num);
		++i;
	}

	
	for(int i = 0; i < (int)odd_pos.size(); ++i){
		for(int j = i +1; j < (int)odd_pos.size(); ++j){
			int msd_i = odd_pos[i] >= 10 ? odd_pos[i]/10 : 0;
			int msd_j = odd_pos[j] >= 10 ? odd_pos[j]/10 : 0;
			if(msd_i == msd_j)
				significant_bit_count[msd_i]++;
		}
	}

	for(int i = 0; i < (int)even_pos.size(); ++i){
		for(int j = i +1; j < (int)even_pos.size(); ++j){
			int msd_i = even_pos[i] >= 10 ? even_pos[i]/10 : 0;
			int msd_j = even_pos[j] >= 10 ? even_pos[j]/10 : 0;
			if(msd_i == msd_j)
				significant_bit_count[msd_i]++;
		}
	}
	for(int i = 0; i <= 9; ++i){
		res += significant_bit_count[i] >= 2 ? 2 : significant_bit_count[i];
	}

	cout << res;

}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
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
	