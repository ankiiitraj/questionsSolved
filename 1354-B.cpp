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
		string s;
		cin >> s;
		int n = s.length();

		int ans = LONG_MAX, cur = 0;
		int one = -1, two = -1, three = -1;
		for(int i = 0; i < n; ++i){
			cur++;
			if(s[i] == '1'){
				one = i;
			}else if(s[i] == '2'){
				two = i;
			}else{
				three = i;
			}
			if(max({one, two, three}) - min({one, two, three}) < ans and one != -1 and two != -1 and three != -1){
				ans = max({one, two, three}) - min({one, two, three}) +1;
				// cur = one = two = three = 0;
			}
		}	
		cout << (ans > 200000 ? 0 : ans) << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	