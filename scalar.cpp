#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/
bool visited[100005] = {0};
vector<int> wa[100005], ta[100005];




void dfs2(int root){
    visited[root] = 1;
    for(auto itr:ta[root]){
        if(!visited[itr])
            dfs(itr);
    }
}

void dfs(int root){
    visited[root] = 1;
    for(auto itr:wa[root]){
        if(!visited[itr])
            dfs(itr);
    }
}

int power(int x, int y, int mod){
    if(y == 0)
        return 1;
    if(y&1){
        return (x*power(x, y -1, mod))%mod;
    }
    int temp = power(x, y/2, mod)%mod;
    return (temp*temp)%mod;
}


int solve(int n, vector<vector<int> > &w, vector<vector<int> > &t) {
    
    int nW = w.size(), nT = t.size();
    int cntW = 0, cntT = 0;
    set<int> walk, talk;
    for(int i = 0; i < nW; ++i){
        walk.insert(w[i][0]);
        walk.insert(w[i][1]);
    }
    for(int i = 0; i < nT; ++i){
        talk.insert(t[i][0]);
        talk.insert(t[i][1]);
    }
    
    for(int i = 0; i < nT; ++i){
        if(walk.find(t[i][1]) != walk.end()){
            return 0;
        }
        if(walk.find(t[i][0]) != walk.end()){
            return 0;
        }
        
    }
    
    for(int i = 0; i < nW; ++i){
        wa[w[i][0]].push_back(w[i][1]);
        wa[w[i][1]].push_back(w[i][0]);
    }
    for(auto &itr:walk){
        if(!visited[itr]){
            dfs(itr);
            cntW++;
        }
    }
    for(int i = 0; i < nT; ++i){
        ta[t[i][0]].push_back(t[i][1]);
        ta[t[i][1]].push_back(t[i][0]);
    }
    for(auto &itr:talk){
        if(!visited[itr]){
            dfs2(itr);
            cntT++;
        }
    }
    return cntT;
    return power(2, cntT + cntW, 1000000007);
    
}


int32_t main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif




}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :


