#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], int src, int par, int dep, int *max_dep, int *node){
    if(adj[src].size() == 1 and par != -1){
        if(dep > *max_dep){
            *node = src;
            *max_dep = dep;
        }
        return;
    }

    for(auto itr: adj[src]){
        if(itr != par){
            dfs(adj, itr, src, dep +1, max_dep, node);
        }
    }
    return;
}
vector<int> ans;
void dfs_(vector<int>adj[], int src, int par, int dep, int max_dep){
    if(adj[src].size() == 1 and par != -1){
        if(dep == max_dep){
            ans[src] = 1;     
        }
        return;
    }

    for(auto itr: adj[src]){
        if(itr != par){
            dfs_(adj, itr, src, dep +1, max_dep);
        }
    }
    return;   
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int n, x, y;
    scanf("%d", &n);
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    vector<int> adj[n +1];
    for(int i = 0; i < n -1; ++i){
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int node = -1, max_dep = -1;
    dfs(adj, 1, -1, 0, &max_dep, &node);
    int first = node;
    max_dep = -1;
    dfs(adj, node, -1, 0, &max_dep, &node);
    int second = node;
    int diameter = max_dep;
    ans.assign(n +1, 0);
    ans[first] = 1;
    dfs_(adj, first, -1, 0, diameter);
    dfs_(adj, second, -1, 0, diameter);
    for(int i = 1; i <= n; ++i){
        if(ans[i] == 1){
            printf("%d\n", diameter +1);
        }else{
            printf("%d\n", diameter);
        }
    }

    return 0;
}