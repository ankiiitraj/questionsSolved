// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Construct Binary Tree
//         		Problem Link : https://codeforces.com/contest/1311/problem/E
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
	int t; cin >> t; while (t--) {
		int n, d;
		cin >> n >> d;
		int logVal = log2(n), minD = 0, maxD = (n * (n - 1)) / 2, totalNode = 1;
		for (int i = 1; i < logVal; ++i)
			minD += (1 << i) * i, totalNode += (1 << i);
		minD += (n - totalNode) * logVal;

		if (d > maxD or d < minD) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			int par[n +1][2] = {0}, curD = maxD;
			for(int i = 2; i <= n; ++i){
				par[i][0] = i -1, par[i -1][1] = 1;
			}
			while(curD > D){
				
			}
		}


	}

	return 0;
}
