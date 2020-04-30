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

int fact[5000000];

struct cell{
	int x, y, v;
};

int power(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x)%MOD;
			--y;
		}else{
			x = (x * x)%MOD;
			y /= 2;
		}
	}
	return ans;
}

inline int subs(int a, int b){
	return (a % MOD - b % MOD + MOD) % MOD;
}
  
int modDivide(int a, int b, int m) 
{ 
    a = a % m; 
    int inv = power(b, m - 2);
    return (inv * a) % m; 
}

int numberOfPaths(int m, int n) 
{ 

    int numerator = fact[n + m -2];
    int denominator = (fact[n -1]*fact[m -1])%MOD;
    int res = modDivide(numerator, denominator, MOD);

    return res;
} 

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		fact[0] = 1;
		for(int i = 1; i < 5000000; ++i){
			fact[i] = (i*fact[i -1])%MOD;
		}

		int n, m, k, w;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&w);
		
		cell a[k];
		for(int i = 0; i < k; ++i){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
		}
		int total = numberOfPaths(n, m)%MOD;
		for(int i = 0; i < k; ++i){
			if(a[i].v % 100000007700000049 == 0){
				int temp = ((numberOfPaths(n - a[i].x +1, m - a[i].y +1)%MOD) * (numberOfPaths(a[i].x, a[i].y)%MOD))%MOD;
				total = subs(total, temp)%MOD;
			}else if(a[i].v % 100000007 == 0 or a[i].v % 1000000007 == 0){
				for(int j = 0; j < k; ++j){
					if(a[i].x <= a[j].x and a[i].y <= a[j].y){
						if(i != j and ((a[i].v % 100000007 == 0 and a[j].v % 1000000007 == 0) or (a[j].v % 100000007 == 0 and a[i].v % 1000000007 == 0))){
							int temp = ((((numberOfPaths(a[i].x, a[i].y)%MOD) * (numberOfPaths(a[j].x - a[i].x +1, a[j].y - a[i].y +1)%MOD))%MOD) * (numberOfPaths(n - a[j].x +1, m - a[j].y +1)%MOD))%MOD;
							total = subs(total, temp)%MOD;
						}
					}
				}	
			}
		}
		printf("%lld\n", total);
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	