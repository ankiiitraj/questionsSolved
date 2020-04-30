// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    ODD TOPICS
//         		Problem Link : https://www.codechef.com/AABH2020/problems/ODTPIC
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <bits/stdc++.h>
#define int long long int
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define len length
#define pb push_back
#define F first
#define S second
#define arrin(a, n) for(int i = 0, i < n; ++i) cin >> a[i];
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
	// int t; cin >> t; while (t--)
	{
		int n, m, q, temp, l1 ,l2, r1, r2;
		cin >> n >> m >> q;

		bitset <4001> a[n], b[m], c1, c2;
		for (int i = 0; i < n; ++i){
			cin >> temp;
			if(i == 0){
				a[i][temp] = 1;
			}else{
				a[i] = a[i -1];
				a[i][temp] = !a[i -1][temp];
			}
		}
		for (int i = 0; i < m; ++i){
			cin >> temp;
			if(i == 0){
				b[i][temp] = 1;
			}else{
				b[i] = b[i -1];
				b[i][temp] = !b[i -1][temp];	
			}
		}

		while(q--){
			c1.reset(), c2.reset();
			cin >> l1 >> r1 >> l2 >> r2;
			--l1, --l2, --r1, --r2;
			if(l1 != 0){
				c1 = a[l1 -1]^a[r1];
			}else{
				c1 = a[r1];
			}
			if(l2 != 0){
				c2 = b[l2 -1]^b[r2];
			}else{
				c2 = b[r2];
			}
			cout << (c1^c2).count() << endl;
		}

	}

	return 0;
}
