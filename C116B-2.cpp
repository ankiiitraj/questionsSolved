#include <bits/stdc++.h>
#define int long long int
#define len length
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
		int n, res = 0;
		cin >> n;
		vi a(n), pos;
		scnarr(a, n);

		int _max = -1;
		for(int i = 0; i < n; ++i)
			_max = max(_max, a[i]);
		
		for(int i = 0; i < n; ++i){
			if(a[i] == _max)
				pos.push_back(i);
			continue;
		}

		if(pos.size() > n/2){
			cout << 0 << endl;
			continue;
		}else if(pos.size() == 1){
			cout << n/2 << endl;
			continue;
		}


		sort(all(pos));
		int max_diff = pos[pos.size() -1] - pos[0] +1;

		if(max_diff > n/2){
			cout << 0 << endl;
		}else{
			cout << n/2 - max_diff +1 << endl;
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	