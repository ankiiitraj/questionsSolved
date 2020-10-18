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
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	
}

string to_bin(int n){
	string res;
	while(n){
		res += (n%2 == 0 ? '0' : '1');
		n /= 2;
	}
	reverse(all(res));
	return res;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	cout << "1\n";
	int n = 10, sum = 0, xor_sum = 0;
	int arr[] = {15, 19, 8, 17, 20, 10, 9, 2, 10, 19};
	for(int i = 0; i < n; ++i)
		sum += arr[i], cout << to_bin(arr[i]) << endl, xor_sum += 32^arr[i];

	cout << 1048576*n + sum << endl << xor_sum;
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
	