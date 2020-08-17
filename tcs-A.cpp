#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

bool is_palindrome(string s){
    int l = 0; 
    int h = s.length() - 1; 
  
    while (h > l){ 
        if (s[l++] != s[h--]) 
            return 0; 
    }
    return 1;
} 

void solve(){
	int x, y;
	cin >> x >> y;
	string days[y - x +1], hrs[24], mins[60], sec[60];

	for(int i = x, j = 0; i <= y; ++i, j++){
		days[j] = to_string(i);
	}
	for(int i = 0; i < 24; ++i){
		if(i < 10){
			hrs[i] = "0" + to_string(i);
		}else{
			hrs[i] = to_string(i);
		}
	}
	for(int i = 0; i < 60; ++i){
		if(i < 10){
			mins[i] = "0" + to_string(i);
			sec[i] = "0" + to_string(i);
		}else{
			mins[i] = to_string(i);
			sec[i] = to_string(i);
		}
	}	
	int ans = 0;
	for(int i = 0; i < (y - x +1); ++i){
		for(int j = 0; j < 24; ++j){
			for(int k = 0; k < 60; ++k){
				for(int l = 0; l < 60; ++l){
					string cur = days[i] + hrs[j] + mins[k] + sec[l];
					if(is_palindrome(cur) == true){
						ans++;
					}
				}
			}
		}
	}

	cout << ans;

}

signed main()
{
	solve();
	return 0;
}


//Author : Ankit Raj
//Problem Link :

/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/
	