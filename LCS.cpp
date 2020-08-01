#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define li long
#define lld long double
#define make_pair mp
#define push_back pb
#define rep(i, j, k) for(ll i = j; j < k; ++j)
#define vll vector<ll>
#define len() length()
using namespace std;

int helper(const string &a, const string &b, int i, int j, int n, int m,int memo[][1001])
{
    if(memo[i][j] >= 0)
        return memo[i][j];
    if(i == n +1|| j == m +1)
        memo[i][j] = 0;
    else if(a[i] == b[j])
    {
        memo[i][j] = 1+ helper(a, b, i +1, j +1, n, m, memo);
    }
    else {
        memo[i][j] = max(helper(a, b, i +1, j, n, m, memo), helper(a, b, i, j +1, n, m, memo));
    }
    return memo[i][j];
}
void longestCommonSubsequence(string a, string b) {
    int memo[1001][1001];
    for(int i = 0; i < a.size() +1; ++i)
        for(int j = 0; j < b.size() +1; ++j)
            memo[i][j] = -1;
    cout << helper(a, b, 0, 0, a.size() -1, b.size() -1, memo)<< endl;
}

void  lcs(string a, string b){
    if(a.length() == 0 or b.length() == 0){
        cout << "0\n";
        return;
    }
    
    int dp[a.length() +1][b.length() +1];
    int n = a.length(), m = b.length();
    a = '!' + a;
    b = '!' + b;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                dp[i][j] = max({dp[i -1][j -1] +1, dp[i][j]});
            }else{
                dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        // longestCommonSubsequence(a, b);
        lcs(a, b);
    }
	return 0;
}