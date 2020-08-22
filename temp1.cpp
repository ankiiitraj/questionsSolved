#include<bits/stdc++.h>
using namespace std;
#define fastii        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl         "\n"
#define f0(i,n)     for(int i=0; i<n; i++)
#define f1(i,n)     for(int i=1; i<=n; i++)
#define mp           make_pair
#define pb           push_back
#define F           first
#define S           second
#define ll             long long int
#define pi            pair<int , int>
#define ai(v)       v.begin(),v.end()
#define air(v)     v.rbegin(),v.rend()
#define pii         3.14159265358979323
#define inf     LLONG_MAX
#define fill(a,b)   memset(a,b,sizeof(a))
#define mod 1000000007

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
        res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(ll a)
{
return mod_pow(a , mod-2 , mod);
}
ll l,r,k;
vector<ll>v1 ;

ll specialnum(ll r){
ll ans=0;
ll y,r1;
y=r;
r1=0;
while(y>0){
r1++;
y=y/10;
}

for(int i=r1;i>=1;i--){
ll prf=pow(10,i-1);
ll val=r/prf;
val=(val%10);
int flag=1;
ll cont=0;
f0(q,v1.size()){

if(r1==1){
if(v1[q]<=val&&(v1[q]!=0)){
cont++;
}
}
else if(i==r1){
if(v1[q]<val&&(v1[q]!=0)){
cont++;
}
}else if(i==1){
if(v1[q]<=val){
cont++;
}
}else{
if(v1[q]<val){
cont++;
}
}
if(v1[q]==val)
flag=0;
}
ll vvv=v1.size();
ans+=pow(vvv,i-1)*cont;
if(flag)
return ans;
}
return ans;
}
void solve(){


cin>>l>>r>>k;
if(k==1){
cout<<(r-l+1)<<endl;
return;
}
v1.resize(0);
for(int i=0;i<10;i++){
if(i%k==0){
v1.push_back(i);
}
}
if(r==1000000000000000000){
r--;
}

ll l1,x;
ll r1,y;
x=l;
y=r;
l1=0;
r1=0;
while(x>0){
l1++;
x=x/10;
}
while(y>0){
r1++;
y=y/10;
}
ll ans=0;

if(l1==r1){
ans+=(specialnum(r)-specialnum(l-1));

}else{
ll cc=0;
ll c10c=1;
for(int i=0;i<l1;i++){
cc+=(c10c)*9;
c10c=c10c*10;
}

ans+=(specialnum(cc)-specialnum(l-1));

for(int i=l1+1;i<r1;i++){
ll vvv=v1.size();
ans+=pow(vvv,i-1)*(vvv-1);
}

ans+=specialnum(r);

}cout<<ans<<endl;

}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
fastii;
 int t;
 cin >> t;
 while (t--)
    {
        solve();
    }
 return 0;
}