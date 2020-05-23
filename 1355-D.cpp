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
		int n, s;
		cin >> n >> s;
		if(n == 1){
			if(s == 1){
				cout << "NO\n";
			}else{
				cout << "YES\n" << s << endl << "1\n";
			}
		}else if(s < 2*n){
			cout << "NO\n";
		}else{
			int cur = s/n;
			int sum = cur*n;
			int last = cur + s - sum;
			cout << "YES\n";
			for(int i = 0; i < n -1; ++i){
				cout << cur << " ";
			}
			cout << last << endl << 1 << endl;

		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	