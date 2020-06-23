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

void solve()
{
	int n, b, m; cin >> n >> b >> m;
	int arr[m];
	for (auto &x : arr) cin >> x;

	int s = -1, e = -1;
	int ct = 0;
	for (int i = 0; i < m; ++i)
	{
		if (s <= arr[i] and e >= arr[i]) {
			;
		}
		else {
			int x = arr[i] / b;
			ct++;
			s = (x * b);
			e = min( (x + 1) * b - 1 , n);
		}
	}
	cout << ct;
	cout << '\n';
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
		solve();
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :

	