// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj                                       //
//                      Problem Name    :    Even Subset Sum Problem                      //
//         		Problem Link : https://codeforces.com/contest/1323/problem/A              //
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
		int n, m, k, ans = 0;
		cin >> n >> m >> k;
		vector <int> a(n), b(m);
		map <int, int> aOnes, bOnes;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < m; ++i)
			cin >> b[i];

		for(int i = 0; i < n; ++i){
			if(a[i] == 1){
				int j = i, cnt = 0;
				while(a[j] == 1 and j < n){
					++j;
					cnt++;
				}
				i = j;
				for(int i = 1; i < cnt; ++i)
					aOnes[i] += cnt - i +1;
				aOnes[cnt]++;
			}
		}

		for(int i = 0; i < m; ++i){
			if(b[i] == 1){
				int j = i, cnt = 0;
				while(b[j] == 1 and j < m){
					++j;
					cnt++;
				}
				for(int i = 1; i < cnt; ++i)
					bOnes[i] += cnt - i +1;
				bOnes[cnt]++;
				i = j;
			}
		}
		for(int i = 1; i <= n; ++i){
			if(k%i == 0 and k/i <= m){
				ans += aOnes[i]*bOnes[k/i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
