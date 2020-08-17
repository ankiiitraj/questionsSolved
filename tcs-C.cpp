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

string ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string two_digs[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int count_vowels(string s){
	int cnt = 0;
	for(char itr: s){
		if(vowels.find(itr) != vowels.end())
			cnt++;
	}
	return cnt;
}

string number_to_string(int n){
	if(n == 100){
		return "hundred";
	}if(n < 10){
		return ones[n];
	}else if(n < 20){
		return two_digs[n%10];
	}else if(n%10 == 0){
		return tens[n/10];
	}else{
		return (tens[n/10] + ones[n%10]);
	}
}

void solve(){
	int n, cnt = 0, ans = 0;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	
	for(int itr: a){
		string num = number_to_string(itr);
		cnt += count_vowels(num);
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i != j and a[i] + a[j] == cnt){
				ans++;
			}
		}
	}
	ans /= 2;
	for(int i = 0; i < n; ++i){
		if(2*a[i] == cnt)
			ans++;
	}
	if(ans == 100){
		cout << "hundred";
	}else if(ans > 100){
		cout << "\"greater 100\"";
	}else{
		cout << number_to_string(ans);
	}
}

signed main()
{
// 	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	// int t; cin >> t; while(t--)
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
	