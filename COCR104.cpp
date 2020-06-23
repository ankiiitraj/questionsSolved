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

int solve(int r, int a, int b){
	int cnt = (r)/(a + b);
	int len = (a + b)*cnt;
	int ans;
	if(len > r){
		ans =  2*cnt -1;
	}else{
		if(a + len <= r)
			ans = 2*cnt +1;
		else
			ans = 2*cnt;
	}
	return ans;
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int a, b, l, r;
		cin >> a >> b >> l >> r;

		
		cout << (solve(r, a, b) - solve(l > 0 ? l -1 : l, a, b)) << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	