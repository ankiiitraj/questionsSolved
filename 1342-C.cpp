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

/* -------------------------------Solution Sarted-------------------------------*/

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int a, b, q, l, r;

		cin >> a >> b >> q;

		if(a > b){
			b ^= a;
			a ^= b; 
			b ^= a;
		}

		while(q--){
			cin >> l >> r;
			if(r < b){
				cout << 0 << " ";
			}else if(b%a != 0){
				int lcm = (a*b)/(__gcd(a, b));
				
				int toSubsR = (r/lcm)*b + min(b, r + 1 - (r/lcm)*lcm);
				int toSubsL = ((l -1)/lcm)*b + min(b, l - ((l -1)/lcm)*lcm);

				cout << r - l +1 - (toSubsR - toSubsL) << " ";
			}else{
				cout << 0 << " ";
			}
		}
		cout << endl;
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	