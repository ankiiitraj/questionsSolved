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
int n, m;
string s[100];

string solve(string ans, int pos, int tries){
	if(pos >= n){
		for(int i = 0; i < n; ++i){
			int cnt = 0;
			for(int j = 0; j < m; ++j){
				if(ans[j] != s[i][j]){
					cnt++;
				}
			}
			if(cnt > 1){
				return "-1";
			}
		}
		return ans;
	}

	int cnt = 0;
	for(int i = 0; i < m; ++i){
		if(ans[i] != s[pos][i]){
			cnt++;
		}
	}

	if(cnt > 2){
		return "-1";
	}else if(cnt == 2 and tries != 0){
		for(int i = 0; i < m; ++i){
			if(ans[i] != s[pos][i]){
				string temp = ans;
				temp[i] = s[pos][i];
				if(solve(temp, pos +1, 0) != "-1")
					return temp;
			}
		}
		return "-1";
	}else if(cnt == 2 and tries == 0){
		return "-1";
	}else{
		return solve(ans, pos +1, 1);
	}

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
		cin >> n >> m;

		for(int i = 0; i < n; ++i){
			cin >> s[i];
		}

		string ans = s[0];

		cout << solve(ans, 1, 1) << endl;


	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	