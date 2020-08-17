#include<bits/stdc++.h>
using namespace std;

int arr[3005], size[3005];

struct edge{
    int u, v, w;
};

bool cmp(edge &e1, edge &e2){
    if(e1.w == e2.w)
        return e1.u + e1.v + e1.w < e2.u + e2.v + e2.w;
    return e1.w < e2.w;
}

void init(int n){
    for(int i = 1; i <= n; ++i){
        size[i] = 1;
        arr[i] = i;
    }
}

int find_head(int x){
    if(arr[x] == x){
        return x;
    }
    return (arr[x] = find_head(arr[x]));
}

void _union(int u, int v){
    if(size[u] > size[v]){
        size[u] += size[v];
        size[v] = 0;
        arr[v] = u;
    }else{
        size[v] += size[u];
        size[u] = 0;
        arr[u] = v;
    }
}

int main(){
    int n, m, x, y, wt, ans = 0;
    cin >> n >> m;
    init(n);
    vector<edge> v(m);
    for(int i = 0; i < m; ++i){
        cin >> v[i].u >> v[i].v >> v[i].w;
    }
    sort(v.begin(), v.end(), cmp);

    for(auto itr: v){
        int u = itr.u, v = itr.v;
        u = find_head(u);
        v = find_head(v);
        if(u != v){
            ans += itr.w;
            _union(u, v);
        }
    }
    cout << ans << endl;
}