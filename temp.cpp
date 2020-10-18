#include<bits/stdc++.h>
#define int long long
using namespace std;

map<pair<int, vector<int>>, int> dp;

int rec(vector<int> a, int score){
    if(a.size() == 1){
        return 0;
    }

    if(dp.count({score, a})){
        return dp[{score, a}];
    }
    int sum = 0;
    for(int i = 1; i < a.size(); ++i){
        vector<int> temp = a;
        int cur = a[i] + a[i -1];
        temp.erase(temp.begin() + i -1);
        temp.erase(temp.begin() + i -1);
        temp.insert(temp.begin() + i -1, cur);
        sum += rec(temp, score + cur) + cur;
    }

    return dp[{score, a}] = sum;

}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    cout << fixed << setprecision(9);
    int t; cin >> t; for(int test = 1; test <= t; ++test){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int cnt = 24;
        dp.clear();
        int total_score = rec(a, 0);
        double res = (double)((total_score * 1.0)/(cnt * 1.0));
        cout << "Case #" << test << ": " << res << endl;
        cout << total_score << endl;
    }
    return 0;
}