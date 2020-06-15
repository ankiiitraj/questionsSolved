// Inefficient - takes exponential time

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
string s;
int n;
vi a;

bool solve(int pos, int x){
	if(pos >= n){
		if(x == 0)
			return true;
		return false;
	}

	bool fir = solve(pos +1, x), sec = solve(pos +1, x^a[pos]);

	if(s[pos] == '0'){
		return fir or sec;
	}
	return fir and sec;

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
		int x = 0;
		cin >> n;
		a.resize(n);
		scnarr(a, n);
		cin >> s;

		if(solve(0, 0))
			cout << 0 << endl;
		else
			cout << 1 << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	