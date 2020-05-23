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

inline int mod(int a, int b){
	int r = a%b;
	if(r < 0){
		r += b;
	}
	return r;
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// cout << mod(-1, 5) << endl;
	int t; cin >> t; while(t--)
	{
		int n;
		cin >> n;
		vi a(n);
		scnarr(a, n);
		mii m;
		for(int i = -n; i <=n; ++i){
			m[i + a[mod(i, n)]]++;
		}

		if(m.size() == 2*n +1){
			puts("YES");
		}else{
			puts("NO");
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
