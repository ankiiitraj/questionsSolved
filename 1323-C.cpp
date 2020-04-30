// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj                                       //
//                      Problem Name    :    Unusual Competitions                         //
//         		Problem Link : https://codeforces.com/contest/1323/problem/C              //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
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
	// int t; cin >> t; while(t--)
	{
		int n, cnt = 0, ans = 0;
		cin >> n;

		string s;
		cin >> s;
		for (int i = 0; i < n; ++i)
			if (s[i] == ')')
				cnt++;
		if (n & 1) {
			cout << -1 << endl;
			return 0;
		}
		if (cnt != n / 2) {
			cout << -1 << endl;
			return 0;
		}
		int i = 0, open = 0, closed = 0;
		while (i < n) {
			if (s[i] == '(')
				open++;
			else
				closed++;

			if (open < closed) {
				int j = i;
				while (open != closed)
				{
					++j;
					if (s[j] == '(')
						open++;
					else
						closed++;
				}
				ans += j - i +1;
				i = j;
			}
			++i;
		}
		cout << ans << endl;


	}
	return 0;
}
