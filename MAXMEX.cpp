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
		int n, m;
		cin >> n >> m;
		vi a(n);
		scnarr(a, n);
		int cnt = 0;
		set<int> s;

		for(int i = 0; i < n; ++i){
			if(a[i] < m)
				s.insert(a[i]);
			else if(a[i] == m)
				cnt++;
		}

		if(s.size() < m -1){
			cout << -1 << endl;
		}else{
			cout << n - cnt << endl;
		}
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	