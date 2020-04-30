#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/* -------------------------------Solution Sarted--------------------------------------*/
vi L, P;

string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string lps(const string &s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;
    P.resize(Q.length() +1, 0);
    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    // cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
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
		string s, rev, ans, revAns;
		cin >> s;
		int n = s.len(), lenP = -1, lenS = -1;
		
		for(int i = n -1; i >= 0; --i)
			rev += s[i];
		int i = 0;
		for( ; i < n; ++i){
			if(s[i] != rev[i])
				break;
			ans += s[i];
			revAns = s[i] + revAns;
		}
		if(i == n){
			cout << s << endl;
			continue;
		}

		lps(s.substr(i, n - 2*i));
		P.erase(P.begin());
		// debug(P);
		L = P;
		P.clear();
		// debug(L);
		for(int j = 0; j < 2*(n - 2*i) -2; ++j){
			if(L[j] == j){
				lenP = L[j];
			}
		}

		lps(rev.substr(i, n - 2*i));
		P.erase(P.begin());
		L = P;
		P.clear();
		for(int j = 0; j < 2*(n - 2*i) -2; ++j){
			if(L[j] == j){
				lenS = L[j];
			}
		}

		if(lenP >= lenS){
			string temp;
			for(int j = i; j < i + lenP; ++j)
				temp += s[j];

			cout << ans << temp << revAns << endl;
		}else{	
			string temp;
			for(int j = i; j < i + lenS; ++j)
				temp += rev[j];

			cout << ans << temp << revAns << endl;
		}

	}
	return 0;
}
