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

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n;
		cin >> n;
		vi a(n);
		scnarr(a, n);

		int even = 0, odd = 0;
		for(int i = 0; i < n; ++i){
			if(i%2 == 0 and a[i]%2 != 0){
				even++;
			}
			if(i&1 and a[i]%2 != 1){
				odd++;
			}
		}
		
		if(even != odd){
			cout << -1 << endl;
		}else{
			cout << even << endl;
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	