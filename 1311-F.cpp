// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Moving Points
//         		Problem Link : https://codeforces.com/contest/1311/problem/F
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while (t--)
	{
		int n, cntP = 1, cntN = 1, ans = 0, temp;
		cin >> n;
		int x[n];
		map <int, pair<int, int>> vp, vn;
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			if (temp >= 0) {
				vp.insert({x[i], {temp, cntP}});
			} else {
				vn.insert({x[i], {temp, cntN}});
			}
		}

		for (auto &itr : vp) {
			int curX = itr.first, curV = itr.second.first;
			auto it = vn.lower_bound(curX);
			if (curX == it->first) {
				ans += it->second.second - 1;
			} else {
				ans += it->second.second;
			}

		}


	}

	return 0;
}
