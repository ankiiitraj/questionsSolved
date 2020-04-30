#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t;
    for(int test = 1; test <= t; ++test){
        
        string str;
        cin >> str;
        
        string ans;
        int open = 0, cur;
        
        for(int i = 0; i < str.length(); ++i){
            cur = str[i] - '0';
            if(open > cur){
                int cnt = open;
                for(int j = 0; j < open - cur; ++j){
                    ans += ')';
                    cnt--;
                }
                open = cnt;
                ans += str[i];
            }else{
                int cnt = open;
                for(int j = 0; j < cur - open; ++j){
                    ans += '(';
                    cnt++;
                }
                open = cnt;
                ans += str[i];
            }
        }
        for(int i = 0; i < open; ++i){
            ans += ')';
        }
        
        cout << "Case #" << test << ": " << ans << endl;
    }
}