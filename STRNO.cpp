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
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int32_t main()
{

	// faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int x, k, cnt = 0;
		cin >> x >> k;
		int newX = x;
		if(log2(x) < k){
			puts("0");
		}else{
			while(x % 2 == 0) { 
	            cnt++;
	            x /= 2;
	        }
			for(int i = 3; i <= sqrt(x); i += 2){
		        while(x % i == 0) { 
		            cnt++;
		            x /= i;
		        }
		    } 
		    if(x > 2)
		    	cnt++;
			if(cnt >= k){
				puts("1");
			}else{
				puts("0");
			}
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	