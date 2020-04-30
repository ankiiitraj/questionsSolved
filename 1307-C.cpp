// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//                             Author : Ankit Raj 
//                         Problem Name : Cow and Secret Message
//         Problem Link : https://codeforces.com/contest/1307/problem/C
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define F first
#define S second
using namespace std;


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.length(), dp[26][26] = {0}, ans = INT_MIN, ansSame = INT_MIN;

    for(int i = 0; i < n; ++i)
    {
        int curChar = s[i] - 'a';
        dp[curChar][curChar] += 1;
        for(int j = 0; j < 26; ++j)
        {
            if(curChar != j)
                dp[curChar][j] += dp[j][j];
        }
    }
    
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if(i == j)
                ansSame = max(ansSame, (dp[i][j]*(dp[i][j] -1))/2);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << max(ans, ansSame) << endl;

    return 0;
}