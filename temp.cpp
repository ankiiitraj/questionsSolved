#include<bits/stdc++.h>
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

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ranks(n, vector<int>(m));
    vector<int> freq(m +1, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> ranks[i][j];
        }
        freq[ranks[i][0]]++;
    }
    vector<pair<int, int>> new_rank;
    for(int i = 1; i <= m; ++i){
        new_rank.push_back({i, freq[i]});
    }
    
    sort(new_rank.begin(), new_rank.end(), cmp);
    int ans = new_rank[0].first, cnt = 0;

    vector<int> idx(n, 0), visited(m +1, 0);
    while(true){
        map<int, int> map;
        vector<pair<int, int>> v;

        for(int i = 0; i < n; ++i){
            if(idx[i] < m and !visited[ranks[i][idx[i]]]){
                map[ranks[i][idx[i]]]++;
            }
        }

        for(auto itr: map){
            v.push_back({itr.first, itr.second});
        }
        sort(v.begin(), v.end(), cmp);
        if(v[0].first == k){
            cout << ans << endl << cnt;
            return 0;
        }
        visited[v[0].first] = 1;
        for(int i = 0; i < n; ++i){
            if(idx[i] < m and ranks[i][idx[i]] == v[0].first){
                while(idx[i] < m and visited[rank[i][idx[i]]]){
                    idx[i]++;
                }
            }
        }
        cnt++;
    }


}