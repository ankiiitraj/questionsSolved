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
		int h, c, t, res;
		double ans = 1000000000000.00;
		cin >> h >> c >> t;

		if(t >= h){
			cout << 1 << endl;
		}else if(t <= (double)(h + c)/2){
			cout << 2 << endl;
		}else{
			int l = 1, r = 100000000000000000, mid = (l + r)/2;
			while(l < r){
				mid = l + (r - l) / 2;
				if(mid%2==0)
					mid++;
				double avg = (double)((mid/2 +1)*h + (mid/2)*c)/mid;
				
				if(t >= avg){
					r = mid -1;
				}else{
					l = mid +1;
				}

				if(ans >= abs(t - avg)){
					ans = abs(t - avg);
					res = mid;
				}

			}
			cout << res << endl;

		}


	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	