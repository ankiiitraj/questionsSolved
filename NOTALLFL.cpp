#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
// const int N = 100005;

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n], fre[100005] = {0}, cnt = 0, curMax = -1, len = 0;
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		for (int i = 0, j = 0; i < n; ++i){
			while(cnt != k -1 and j < n){
				if(fre[a[j]] == 0)
					cnt++;
				fre[a[j]]++;
				++j;
				len++;
			}
			curMax = max(curMax, len);
			fre[a[i]]--;
			if(fre[a[i]] == 0)
				cnt--;
			len--;
		}

		cout << curMax << endl;
	}
}