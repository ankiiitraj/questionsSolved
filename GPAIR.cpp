#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/

const int MAXN = 5000005 ;//define a value here
bool prime[MAXN +1];
void sieve(){
	prime[0] = prime[1] = 1;
	for(int i = 2; i*i <= MAXN; ++i){
		if(!prime[i]){
			for(int j = i*i; j <= MAXN; j += i){
				prime[j] = 1;
			}
		}
	}
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
		sieve();
	int t; cin >> t; while(t--)
	{
		int n, ans = 0;
		cin >> n;
		vi a(n);
		scnarr(a, n);
		for(int i = 0; i < n; ++i){\
			for(int j = i +1; j < n; ++j){
				if(prime[a[i] + a[j]] == 0)
					ans++;
			}
		}
		cout << ans << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
