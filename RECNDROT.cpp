#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
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
	int t; scanf("%lld", &t); while(t--)
	{
		int n, ans = 0;
		scanf("%lld", &n);
		vi a(n);
		scnarr(a, n);
		unordered_map<int, set<int>>m;
		set <int> s;
		for(int i = 0; i < n; ++i){
			m[a[i]].insert(i);
			s.insert(a[i]);
		}

		int prev = -1, cnt = 0;
		auto itr = s.begin();
		while(!s.empty()){
			int cur = *s.begin();
			s.erase(s.begin());

			if(prev == -1){
				prev = *(m[cur].begin());
			}

			if(m[*s.begin()].lower_bound(prev) == m[*s.begin()].end()){
				prev = -1;
				ans++;
				cnt = 0;

			}else{
				prev = *m[*s.begin()].lower_bound(prev);
			}


		}
		printf("%lld\n", ans);

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	