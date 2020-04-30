#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

inline int mul(int x, int y) {
    int z = 1LL * x * y;
    if (z >= MOD) {
        z %= MOD;
    }
    return z;
}
inline int add(int x, int y) {
    int z = x + y;
    if (z >= MOD) {
        z -= MOD;
    }
    return z;
}
inline int sub(int x, int y) {
    int z = x - y;
    if (z < 0) {
        z += MOD;
    }
    return z;
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, k, ans;
		cin >> n >> k;
		
		if(n == 0){
			cout << mul(k, k -1) << endl;
			continue;
		}

		int numRounds = add(n, k/2)%MOD;

		ans = mul(numRounds, sub(numRounds, 1)%MOD)%MOD;

		if(k&1){
			ans = add(ans, add(numRounds, sub(numRounds, n)));
		}else{
			ans = add(ans, n);
		}
		cout << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	