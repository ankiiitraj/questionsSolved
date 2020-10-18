#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
  int t; cin >> t; while(t--){
    string s;
    cin >> s;
    int n = s.length();
    

    int dist_ch = 0, res = 10000000;
    int start = 0;
    int ch_freq[3] = {0};

    for(int i = 0; i < n; ++i){
      if(ch_freq[s[i] - 'a'] == 0)
        dist_ch++;

      ch_freq[s[i] - 'a']++;

      if(dist_ch == 3){
        while(ch_freq[s[start] - 'a'] > 1){
          ch_freq[s[start] - 'a']--;
          start++;
        }
        res = min(res, i - start +1);
      }
    }

    cout << (res < 3 or res > n  ? -1 : res) << endl;

  }
  
  return 0;
}
