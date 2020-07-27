#include <bits/stdc++.h>

using namespace std;

int dp[5005][5005];

int recurse(int pos1, int pos2, string &a, string &b){
    if(pos1 >= (int)a.length() or pos2 >= (int)b.length()){
        return 0;
    }

    if(dp[pos1][pos2] != -1)
        return dp[pos1][pos2];

    int two, one;
    if(a[pos1] == b[pos2]){
        return dp[pos1][pos2] = recurse(pos1 +1, pos2 +1, a, b) +1;
    }
    two = recurse(pos1 +1, pos2, a, b);
    one = recurse(pos1, pos2 +1, a, b);

    return dp[pos1][pos2] = max({one, two});

}

int tutzkiAndLcs(string a, string b) {
    int res = 0;
    memset(dp, -1, sizeof(dp));
    int cur = recurse(0, 0, a, b);
    for(int i = 0; i <= (int)a.length(); ++i){
        for(char c = 'a'; c <= 'z'; ++c){
            memset(dp, -1, sizeof(dp));
            string s = a.substr(0, i) + c + a.substr(i); 
            if(recurse(0, 0, s, b) == cur +1)
                res++;
        }
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif

    string a;
 
    string b;
    cin >> a >> b;
    int result = tutzkiAndLcs(a, b);

    cout << result << "\n";


    return 0;
}
