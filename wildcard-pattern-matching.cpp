#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}

int wildCard(string p, string s){
    int n = s.length(), cnt = 0;
    string pat;
    for(int i = 0; i < p.length(); ++i){
        if(p[i] != '*'){
            pat += p[i];
        }else
          cnt++;
    }
    int m = pat.length();
    
    int dp[n +1][m +1];
    memset(dp, 0, sizeof dp);
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i -1] == pat[j -1] or pat[j -1] == '?'){
                dp[i][j] = dp[i -1][j -1] +1;
            }else{
                dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
            }
        }
    }

    return (dp[n][m] == m and (cnt == 0 ? m == n : 1));
}