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
		vi a(n), b(n);
		scnarr(a, n);
		scnarr(b, n);
		multiset <pii> ma, mb;

		for(int i = 0; i < n/2; ++i){
			ma.insert({a[i], a[n - i -1]});
			ma.insert({a[n - i -1], a[i]});
			mb.insert({b[i], b[n - i -1]});
			mb.insert({b[n - i -1], b[i]});
		}

		if(ma != mb){
			puts("NO");
		}else if(n&1 and a[n/2] != b[n/2]){
			puts("NO");
		}else{
			puts("YES");
		}
		
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	