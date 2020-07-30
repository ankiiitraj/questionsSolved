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
	int t; cin >> t; while(t--)
	{
		string s;
		cin >> s;
		int n = s.length();

		int and_opp[] = {9, 1, 3, 3}, or_opp[] = {1, 9, 3, 3}, xor_opp[] = {4, 4, 4, 4}, ans[] = {1, 1, 1, 1}, deno = 4;
		int and_hash[][4] = {{4, 0, 0, 0}, {1, 1, 1, 1}, {2, 0, 2, 0}, {2, 0, 0, 2}};
		int or_hash[][4] = {{1, 1, 1, 1}, {0, 4, 0, 0}, {0, 2, 2, 0}, {0, 2, 0, 2}};
		int xor_hash[][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

		for(auto itr: s){
			
			if(itr == '|'){
				deno = (deno * 4)%MOD;
				if(ans[0] == 1 and ans[1] == 1 and ans[2] == 1 and ans[3] == 1){
					for(int i = 0; i < 4; ++i){
						ans[i] = or_opp[i];
					}
					continue;
				}
				int temp_0 = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0;
				for(int i = 0; i < 4; ++i){
					temp_0 = (temp_0 + (ans[i] * or_hash[i][0]) % MOD)%MOD;
					temp_1 = (temp_1 + (ans[i] * or_hash[i][1]) % MOD)%MOD;
					temp_2 = (temp_2 + (ans[i] * or_hash[i][2]) % MOD)%MOD;
					temp_3 = (temp_3 + (ans[i] * or_hash[i][3]) % MOD)%MOD;
				}
				ans[0] = temp_0, ans[1] = temp_1, ans[2] = temp_2, ans[3] = temp_3;
			}else if(itr == '&'){
				deno = (deno * 4)%MOD;
				if(ans[0] == 1 and ans[1] == 1 and ans[2] == 1 and ans[3] == 1){
					for(int i = 0; i < 4; ++i){
						ans[i] = and_opp[i];
					}
					continue;
				}
				int temp_0 = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0;
				for(int i = 0; i < 4; ++i){
					temp_0 = (temp_0 + (ans[i] * and_hash[i][0]) % MOD)%MOD;
					temp_1 = (temp_1 + (ans[i] * and_hash[i][1]) % MOD)%MOD;
					temp_2 = (temp_2 + (ans[i] * and_hash[i][2]) % MOD)%MOD;
					temp_3 = (temp_3 + (ans[i] * and_hash[i][3]) % MOD)%MOD;
				}
				ans[0] = temp_0, ans[1] = temp_1, ans[2] = temp_2, ans[3] = temp_3;
			}else if(itr == '^'){
				deno = (deno * 4)%MOD;
				if(ans[0] == 1 and ans[1] == 1 and ans[2] == 1 and ans[3] == 1){
					for(int i = 0; i < 4; ++i){
						ans[i] = xor_opp[i];
					}
					continue;
				}
				int temp_0 = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0;
				for(int i = 0; i < 4; ++i){
					temp_0 = (temp_0 + (ans[i] * xor_hash[i][0]) % MOD)%MOD;
					temp_1 = (temp_1 + (ans[i] * xor_hash[i][1]) % MOD)%MOD;
					temp_2 = (temp_2 + (ans[i] * xor_hash[i][2]) % MOD)%MOD;
					temp_3 = (temp_3 + (ans[i] * xor_hash[i][3]) % MOD)%MOD;
				}
				ans[0] = temp_0, ans[1] = temp_1, ans[2] = temp_2, ans[3] = temp_3;
			}
			// for(int i = 0; i < 4; ++i)
			// 	cout << ans[i] << " ";
			// cout << endl;
		}

		int gcd = __gcd(deno, ans[0]);
		ans[0] = ((ans[0]/gcd)*(power(deno/gcd, MOD -2))) % MOD;
		
		gcd = __gcd(deno, ans[1]);
		ans[1] = ((ans[1]/gcd)*(power(deno/gcd, MOD -2))) % MOD;

		gcd = __gcd(deno, ans[2]);
		ans[2] = ((ans[2]/gcd)*(power(deno/gcd, MOD -2))) % MOD;

		gcd = __gcd(deno, ans[3]);
		ans[3] = ((ans[3]/gcd)*(power(deno/gcd, MOD -2))) % MOD;


		cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
