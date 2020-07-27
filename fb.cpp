// #include<bits/stdc++.h>
// using namespace std;

// using   int=long long;
// using   ld=long double;

// #define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define ordered_set tree<pint, nuint_type,less<pint>, rb_tree_tag,tree_order_statistics_node_update>

// #define endl         "\n"
// #define pb           push_back
// #define mp           make_pair
// #define F           first
// #define S           second
// #define int             long long int
// #define pint pair<int , int>

// #define ALL(v)       v.begin(),v.end()
// #define ALLR(v)     v.rbegin(),v.rend()
// #define pii         3.14159265358979323
// #define inf     LLONG_MAX
// #define ones(x)     __builtin_popcount(x)
// #define fiint(a,b)   memset(a,b,sizeof(a))
// #define mod 1000000007
// #define heint            998244353

// int mod_pow(int a,int b,int m)
// {
//     int res = 1;
//     while(b)
//     {
//         if(b&1)
//         {
//         res=(res*a) % m;
//         }
//         a=(a*a) % m;
//         b>>=1;
//     }
//     return res;
// }

// int mod_inverse(int a)
// {
// return mod_pow(a , mod-2 , mod);
// }

// void solve()
// {
// int n;

// cin >> n;

// vector< pair< int , int> > a(n);

// for(int i = 0; i < n; ++i) {
// cin >> a[i].F >> a[i].S;
// }

// sort(ALL(a));

// map<int , int> f1;
// map<int , int> f2;

// int mx = 0;

// for(int i = 0; i < n; ++i) {
// int x = a[i].F;
// int y = a[i].S;

// int tm = f1[x];

// f1[x + y] = max(f1[x + y] , y + tm);

// mx = max(mx , f1[x + y]);
// }

// for(int i = n-1; i >= 0; --i) {
// int x = a[i].F;
// int y = a[i].S;

// int p = x - y;

// int tm = f2[x];

// f2[p] = max(f2[p] , y + tm);

// mx = max(mx , f2[p] + f1[p]);
// }

// cout << mx << endl;
// }

// signed main() {
//     fast;
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif

//     int t = 1;

// cin >> t;

//     int i = 1;

//     while(t--) {

//     cout << "Case #" << i << ": ";

//         solve();

//         ++i;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t;

void update(ll node,ll s,ll e,ll l,ll r,ll val,vector<ll> &tree){
ll p=node/2;
if(p>0) tree[node]=min(tree[p],tree[node]);
if(s>r || e<l) return;
if(l<=s && r>=e){
tree[node]=min(tree[node],val);
return;
}
ll mid=(s+e)/2;
update(2*node,s,mid,l,r,val,tree);
update(2*node+1,mid+1,e,l,r,val,tree);
return;
}


ll find(ll node,ll s,ll e,ll ind,vector<ll> &tree){
ll p=node/2;
if(p>0) tree[node]=min(tree[p],tree[node]);

if(s==e)
return tree[node];

ll mid=(s+e)/2;
if(ind<=mid) return find(2*node,s,mid,ind,tree);
return find(2*node+1,mid+1,e,ind,tree);
}


void solve(){
ll n,m,ans;
cin>>n>>m;
vector<ll> tree(4*n+5,1e18);
update(1,0,n-1,0,min(m,n-1),0,tree);

for(ll i=0;i<n;i++){
ll x;
cin>>x;
if(x==0) continue;

ll val=find(1,0,n-1,i,tree)+x;

update(1,0,n-1,i+1,min(n-1,i+m),val,tree);

}

ans=find(1,0,n-1,n-1,tree);
if(ans>=1e18) ans=-1;

for(int i = 0; i <= n; ++i)
    cout << find(1,0,n-1,i,tree) << " ";

cout<<ans<<endl;
return;
}


signed main() {

#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
 cin.tie(0);

    int q = 1;


cin >> q;

    for(int tc=1;tc<=q;tc++){
        cout<<"Case #"<<tc<<": ";
        solve();
    }

    return 0;
}

