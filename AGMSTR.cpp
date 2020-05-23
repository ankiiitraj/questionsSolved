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
		int n = s.length(), cnt = 0; 
		int arr[n];
		for(int i = 0; i < n; ++i){
			if(s[i] == 'a'){
				arr[i] = -1;
			}else{
				arr[i] = 1;
			}
		}
		int x = 0, y = 0, cur = 0, ans = 0, tempi = 0;
		for(int i = 0; i < n; ++i){
			cur += arr[i];
			if(cur < 0){
				tempi = i +1;
				cur = 0;
			}
			if(cur > ans){
				x = tempi;
				y = i;
				ans = cur;
			}
		}
		cout << x << " " << y << endl;
		for(int i = x; i <= y; ++i){
			if(s[i] == 'a'){
				s[i] = 'b';
			}else{
				s[i] = 'a';
			}
		}
		for(auto itr: s){
			if(itr == 'a'){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	