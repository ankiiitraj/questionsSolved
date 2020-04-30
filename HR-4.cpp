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
unordered_map <string, int> dp;
int solve(vi &a, int l, int r, int sum, int p){
    if(l >= r or p <= 0){
        return sum;
    }
    string temp = to_string(l)+'|'+to_string(r);
    if(dp.find(temp) != dp.end())
        return dp[temp];
    dp[temp] = max(solve(a, l +2, r, sum + a[l] + a[l +1], p -1), solve(a, l, r -2, sum + a[r] + a[r -1], p -1));

    return dp[temp];
}

int32_t main()
{
    faster;
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
//     int t; cin >> t; while(t--)
    {
        int n, p, cnt = 1;
        string s;
        cin >> n >> p >> s;

        vi freq;
        dp.clear();
        for(int i = 1; i < n; ++i){
            if(s[i] != s[i -1]){
                freq.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        freq.push_back(cnt);
        if(freq.size() <= 2){
            cout << 0 << endl;
            return 0;
        }else{
            freq.erase(freq.begin());
            freq.pop_back();
        }

        if(s[0] == s[n -1]){
            if(freq.size() <= 1){
                p > 0 ?cout << 0 << endl : cout << freq[0] << endl;
            }else{
                cout << abs(solve(freq, 0, freq.size() -1, 0, p) - accumulate(all(freq), 0)) << endl;
            }
        }else{
            cout << abs(solve(freq, 0, freq.size() -1, 0, p) - accumulate(all(freq), 0)) << endl;
        }


    }
    return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
    