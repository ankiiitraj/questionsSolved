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
const int MOD = 998244353; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int power(int x, int y){
	if(y == 0)
		return 1;
	if(y&1){
		return (x*power(x, y -1))%MOD;
	}
	int temp = power(x, y/2)%MOD;
	return (temp*temp)%MOD;
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif


	cout << p*(power(16,))
	
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	