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
		int n, ans  = 0;
		cin >> n;
		int a, curMax = -1;
		map <int, int> m;
		for(int i = 0; i < n; ++i)
			cin >> a, m[a - i] += a;
		for(auto &itr: m){
			if((int)itr.second > curMax){
				curMax = itr.second;
			}
		}
		cout << curMax << endl;
	}
	
}
