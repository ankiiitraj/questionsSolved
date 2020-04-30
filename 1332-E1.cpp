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
vi a(2005);
int n; 

int solve(int s, int e, int ndist, int last){
	if(s > e){
		return 0;
	}
	if(s == e){
		if(ndist == 0)
			return 1;
		else if(ndist == 1)
			return 1;
		else if(ndist == 2 and a[s] == last)
			return 1;
		else 
			return 0;

	}

	if(ndist == 0){
		if(a[s] == a[e])
			return ( max({solve(s +1, e -1, ndist, last), solve(s +1, e -1, ndist +1, a[s]) +2, solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)}));
		else{	
			return ( max(solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)));
		}
	}

	if(ndist == 1){
		if(a[s] == last){
			if(a[s] == a[e])
				return ( max({solve(s +1, e -1, ndist, last), solve(s +1, e -1, ndist, a[s]) +2, solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)}));
			else{	
				return ( max(solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)));
			}
		}else{
			if(a[s] == a[e])
				return ( max({solve(s +1, e -1, ndist, last), solve(s +1, e -1, ndist +1, a[s]) +2, solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)}));
			else{	
				return ( max(solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)));
			}
		}
	}
	if(ndist == 2){
		if(a[s] == last){
			if(a[s] == a[e])
				return ( max({solve(s +1, e -1, ndist, last), solve(s +1, e -1, ndist, a[s]) +2, solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)}));
			else{	
				return ( max(solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)));
			}
		}else{
			return ( max(solve(s, e -1, ndist, last), solve(s +1, e, ndist, last)));
		}
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
		cin >> n;
		scnarr(a, n);
		
		cout << solve(0, n -1, 0, -1) << endl; 
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	