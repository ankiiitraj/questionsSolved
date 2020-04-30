#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define li long
#define lld long double
#define make_pair mp
#define push_back pb
#define rep(i, j, k) for(ll i = j; j < k; ++j)
#define vll vector<ll>
#define len() length()
using namespace std;

int memo[2005][2005];
int lis(int a[], int prev, int cur, int n){
	if(cur == n)
		return 0;
	if(prev == -1){
	    memo[cur][cur] = max(lis(a, cur, cur +1, n) +1, lis(a, prev, cur +1, n));
	    return memo[cur][cur];
	}
	if(memo[cur][prev] != 0)
		return memo[cur][prev];
	if(a[cur] > a[prev])
		memo[cur][prev] = max(lis(a, cur, cur +1, n) +1, lis(a, prev, cur +1, n));
	else
		memo[cur][prev] = lis(a, prev, cur +1, n);
	return memo[cur][prev];
}

int main()
 {
	int t; cin >> t; while(t--)
	{
	    memset(memo, 0, sizeof(memo));
	    int n; cin >> n;
	    int a[n];
	    for(int i = 0; i < n; ++i)
	        cin >> a[i];
	    cout << max(lis(a, 0, 1, n) +1, lis(a, -1, 1, n)) << endl;
	}
	return 0;
}