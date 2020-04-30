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

string digi[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n, k;
		cin >> n >> k;
		string s[n];
		for(int i = 0; i < n; ++i){
			cin >> s[i];
			int flag = 0;
			for(int j = 0; j < 10; ++j){
				if(s[i] == digi[j]){
					flag = 1;
					break;
				}
			}
			if(!flag){
				for(int j = 9; j >= 0; --j){
					for(int k = 0; k < 7; ++k){
						if(s[i][k] == '1' and digi[j][k] == '0'){
							break;
						}
					}
					int sets = 0;
					for(int k = 0; k < n; ++k){
						if(s[i][k] == '1')
							sets++;
					}
				}
			}
		}



		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	