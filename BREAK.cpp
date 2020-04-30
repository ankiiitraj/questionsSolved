#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(), a.end()
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


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t, s; cin >> t >> s; while(t--)
	{
		int n, flag = 0;
		cin >> n;
		vi a(n), b(n);
		scnarr(a, n);
		scnarr(b, n);

		sort(all(a));
		sort(all(b));

		if(a[0] >= b[0]){
			puts("NO");
			continue;
		}
		
		set <int> s;
		s.insert(a[0]), s.insert(b[0]);
		for (int i = 1; i < n; ++i){
			if(a[i] >= b[i]){
				flag = 1;
				break;
			}
			if(s.find(a[i]) == s.end()){
				flag = 1;
				break;
			}
			s.insert(a[i]), s.insert(b[i]);
		}


		flag ? puts("NO") : puts("YES");

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
