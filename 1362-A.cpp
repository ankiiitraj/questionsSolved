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
		int a, b;
		cin >> a >> b;

		if(a == b){
			cout << 0 << endl;
		}else if(a > b){
			int ans = 0;
			while(a%8 == 0 and a/8 >= b){
				a /= 8;
				ans++;
			}
			while(a%4 == 0 and a/4 >= b){
				a /= 4;
				ans++;
			}
			while(a%2 == 0 and a/2 >= b){
				a /= 2;
				ans++;
			}
			if(a == b){
				cout << ans << endl;
			}else{
				cout << -1 << endl;
			}

		}else{
			int ans = 0;
			while(a*8 <= b){
				a *= 8;
				ans++;
			}
			while(a*4 <= b){
				a *= 4;
				ans++;
			}
			while(a*2 <= b){
				a *= 2;
				ans++;
			}
			if(a == b){
				cout << ans << endl;
			}else{
				cout << -1 << endl;
			}
		}
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	