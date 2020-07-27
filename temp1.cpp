#include<bits/stdc++.h>
using namespace std; 

string b = "ninjas";

int count(string a) 
{ 
    int m = a.length(); 
    int n = b.length(); 
    int lookup[m + 1][n + 1] = { { 0 } }; 
    for (int i = 0; i <= n; ++i) 
        lookup[0][i] = 0;

    for (int i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 

    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (a[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] + lookup[i - 1][j]; 
            else
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.length(), q, sz;
    char ty;
    cin >> q;
    
    // int pre[n][26], suf[n][26];
    // memset(pre, 0, sizeof(pre));
    // memset(suf, 0, sizeof(suf));
    // pre[0][s[0] - 'a'] = 1;
    // for(int i = 1; i < n; ++i){
    //     for(int j = 0; j < 26; ++j)
    //         pre[i][j] = pre[i -1][j];
    //     suf[i][s[i] - 'a']++;
    // }
    // suf[n -1][s[n -1] - 'a'] = 1;
    // for(int i = n -2; i >= 0; --i){
    //     for(int j = 0; j < 26; ++j)
    //         suf[i][j] = suf[i +1][j];
    //     suf[i][s[i] - 'a']++;
    // }
    
    
    while(q--){
        cin >> ty >> sz;
        int res = 0;
        if(ty == 'p'){
            cout << count(s.substr(0, sz)) << endl;
        }else{
            cout << count(s.substr(n - sz)) << endl;
        }
    }
}