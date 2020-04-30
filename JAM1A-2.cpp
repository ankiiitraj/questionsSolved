#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int test;
    cin >> test;
    for(int t = 1; t <= test; ++t)
    {
        int n, _max = -1, flag = 0;
        cin >> n;
        string s[n], ans;
        for(int i = 0; i < n; ++i){
            cin >> s[i];
            int len = s[i].length();
            if(len > _max){
                _max = s[i].length();
                ans = s[i];
            }
        }

        for(int i = 0; i < n; ++i){
            string cur = s[i];
            int len = cur.length();
            for(int j = len -1, k = ans.length() -1; j >= 1; --j, --k){
                if(cur[j] != ans[k]){
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        cout << "Case #" << t << ": " << (flag ? "*" : ans.substr(1)) << endl;
    }
}