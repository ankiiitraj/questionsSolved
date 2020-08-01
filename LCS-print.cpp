#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;

int dp[105][105];
set<string> lcses;
int lcs_cnt;
void print_lcs(int n, int m, string a, string b, string ans){
    if(ans.size() == lcs_cnt){
        lcses.insert(ans);
        return;
    }
    
    for(int i = n; i > 0; --i){
        for(int j = m; j > 0; --j){
            if(a[i -1] == b[j -1] and ans.size() == lcs_cnt - dp[i][j]){
                print_lcs(i -1, j -1, a, b, a[i -1] + ans);
            }
        }
    }
}

void  lcs(int n, int m, string a, string b){

    memset(dp, 0, sizeof dp);
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i -1] == b[j -1]){
                dp[i][j] = max({dp[i -1][j -1] +1, dp[i][j]});
            }else{
                dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
            }
        }
    }
    lcs_cnt = dp[n][m];
    cout << lcs_cnt << endl;
    string ans;
    print_lcs(n, m, a, b, ans);
    for(auto itr: lcses){
        string temp = itr;
        cout << itr << " ";
    }
    cout << endl;
    lcses.clear();
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
        string a, b;
        cin >> a >> b;
        int n = a.length(), m = b.length();
        // longestCommonSubsequence(a, b);
        lcs(n, m, a, b);
    }
    return 0;
}
