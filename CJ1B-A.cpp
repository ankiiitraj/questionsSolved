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
	int t; cin >> t; for(int test = 1; test <= t; ++test)
	{
		int x, y;
		cin >> x >> y;

		bitset <32> sx(x), sy(y);

		int msbX = log2(x), msbY = log2(y), flag = 0;
		char hori = 'E', verti = 'N';
		if(x < 0){
			x = -x;
			hori = 'W';
		}
		if(y < 0){
			y = -y;
			verti = 'S';
		}
		string ans, notAns = "IMPOSSIBLE";

		cout << sx << " " << sy << endl;

		if(msbY == msbX){
			for(int i = 31; i >= 32 - (msbX +1) +1; --i){
				if(sx[i] == sy[i]){
					flag  = 1;
					break;
				}
			}
			if(!flag){
				for(int i = 31; i >= 32 - (msbY +1) +1; --i){
					if(sx[i]){
						ans += hori;
					}else{
						ans += verti;
					}
				}
				if(x%2 == 0){
					ans += verti;
					ans += hori == 'W' ? 'E' : 'W';
				}else{
					ans += hori;
					ans += verti == 'S' ? 'N' : 'S';
				}
			}
		}else{
			for(int i = 31; i >= 0; --i){
				if(sx[i] == sy[i]){
					flag  = 1;
					break;
				}
			}
			if(!flag){
				for(int i = 31; i >= 32 - (min(msbX, msbY) +1); --i){
					if(sx[i]){
						ans += hori;
					}else{
						ans += verti;
					}
				}
			}
		}

		cout << "Case #" << test << ": " << (flag ? notAns : ans) << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	