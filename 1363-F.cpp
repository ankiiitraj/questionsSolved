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
const int INF = 100000000000000000;

/* -------------------------------Solution Sarted--------------------------------------*/
int n;
string t;
int cnt = 0;
int solve(string s){
	if(s == t){
		return 0;
	}

	int ans = INF;
	string cur, temp;
	for(int pos = 0; pos < n; ++pos){
		for(int i = 2; i <= (n - pos); ++i){
			cur = s.substr(pos, i);
			for(int j = 1; j < i; ++j){
				if(j != 0){
					char last = cur[cur.length() -1];
					for(int k = cur.length() -1; k > 0; --k){
						cur[k] = cur[k -1];
					}
					cur[0] = last;
				}
				temp = s.substr(0, pos) + cur + s.substr(pos + i);
				ans = min(ans, j + solve(temp));
			}

		}
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
	int test; cin >> test; while(test--)
	{
		string s;
		cin >> n >> s >> t;
		
		cout << solve(s) << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	