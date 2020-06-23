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
	// int t; cin >> t; while(t--)
	{
		int n, k;
		cin >> n >> k;
		vi a(n), odds, evens;
		scnarr(a, n);
		
		for(int i = 0; i < n; ++i){
			if(i&1){
				odds.push_back(a[i]);
			}else{
				evens.push_back(a[i]);
			}
		}
		sort(all(odds));
		sort(all(evens));

		int odd_max = odds[k/2 -1];
		int even_max = evens[k/2 -1];
		if(k&1){
			even_max = evens[k/2];
		}


		cout << min(odd_max, even_max) << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	
	