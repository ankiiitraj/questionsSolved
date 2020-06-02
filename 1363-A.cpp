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
		int n, x, odd = 0;
		cin >> n >> x;
		vi a(n);
		scnarr(a, n);
		
		for(int i = 0; i < n; ++i){
			if(a[i]&1)
				odd++;
		}

		int even = n - odd;
		if(odd == 0){
			puts("NO");
			continue;
		}
		if(!(odd&1)){
			odd--;
		}
		
		if(x&1 and odd >= x){
			odd = x;
		}
		if(!(x&1) and odd >= x){
			odd = x -1;
		}	
		if(odd + even >= x){
			puts("YES");
		}else{
			puts("NO");
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	