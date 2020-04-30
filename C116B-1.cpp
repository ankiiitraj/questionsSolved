#include <bits/stdc++.h>
#define int long long int
#define len length
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
		int n, res = 0, x =0, y = 0, flag = 0;
		string s;
		cin >> n >> s;
		if(s[0] == 'L' or s[0] == 'R')
			flag = 1;
		for(int i = 0; i < n; ++i){
			if(s[i] == 'L' and flag){
				x -= 1;
				flag = 0;
			}else if(s[i] == 'R' and flag){
				x += 1;
				flag = 0;
			}else if(s[i] == 'U' and !flag){
				y += 1;
				flag = 1;
			}else if(s[i] == 'D' and !flag){
				y -= 1;
				flag = 1;
			}
		}

		cout << x << " " << y << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	