#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
#define MOD 1000000007
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
ll fact[500005];
ll recpow(ll n,ll p ,ll m=MOD)
{
 ll ans=1;
 while(p)
 {
  if(p&1)ans=(ans*n)%m;
  n=(n*n)%m;
  p>>=1;
 }
 
 return ans%m;

}

ll mod_inv(ll n,ll m=MOD)
{
 return recpow(n,m-2,m);
}
ll nCr(ll n, ll r, ll m=MOD)
{
if(r==0)return 1;
return (((fact[n]*mod_inv(fact[n-r]))%m)*mod_inv(fact[r]))%m;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif          
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int t;
 cin>>t;
 fact[0]=fact[1]=1;
 for(int i=2;i<500005;i++)
 {
  fact[i]=(1ll*fact[i-1]*i)%MOD;
 }
 while(t--)
 {
  ll n;
  cin>>n;
  ll a[n+1];
  map<ll,ll> mp;
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
   mp[a[i]]++;
  }
  ll cm[n+3],rem[n+1];
  for(int i=0;i<=n+1;i++)
  {
          cm[i]=rem[i]=1;
  }

  for(auto x:mp)
  {
   ll sum=1;
   for(int j=1;j<=x.second;j++)
   {
                  sum+=nCr(x.second,j);
                  sum%=MOD;
                  cm[j]*=sum;
                  cm[j]%=MOD;        
   }
   rem[x.second+1]*=sum;
   rem[x.second+1]%=MOD;
  }

  ll mul=1;
  for(int i=1;i<=n;i++)
  {
          mul*=rem[i];
          mul%=MOD;
          cm[i]*=mul;
          cm[i]%=MOD;  
  }
  

  for(int i=1;i<=n;i++)
  { 
   ll res=0,ans,sum=1;
  

    for(int j=1;j<=mp[i];j++)
   {
    ll tmp;
              ans=nCr(mp[i],j);
                tmp=ans;
              sum+=ans;
              sum%=MOD;
              cm[j]=(cm[j]*mod_inv(sum))%MOD;
              ans*=cm[j];
              ans%=MOD;
              cm[j]=(cm[j]*(sum-tmp+MOD)%MOD)%MOD;
              res+=ans;
              res%=MOD;
             }
   


   cout<<res%MOD<<" ";
  }
  cout<<endl;

  

 }
return 0;
}