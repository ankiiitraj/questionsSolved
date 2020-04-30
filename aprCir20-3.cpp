

    #include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
    // #define int long long int
    #define pb push_back
    #define all(a) a.begin(), a.end()
    // #define scnarr(a, n) for (int i = 0; i < n; ++i) scanf("%lld",&a[i]);
    #define vi vector<int>
    #define pii pair <int, int>
    #define mii map <int, int>
    #define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
    using namespace std;
    //Constants
    // const int MOD = 1000000007; // 1e9 + 7
    // const int N = 1000005; // 1e6 +5
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
    /* -------------------------------Solution Sarted--------------------------------------*/
     
    int block;
     
    struct query
    {
    	int l, r, id;
    };
     
    bool cmp(query &q1, query &q2){
    	if(q1.l/block != q2.l/block)
    		return q1.l < q2.l;
    	return q1.r < q2.r;
    }
     
     
    int32_t main()
    {
    	faster;
    #ifndef ONLINE_JUDGE
    	freopen("ip.txt", "r", stdin);
    	freopen("op.txt", "w", stdout);
    #endif
    	// int t; cin >> t; while(t--)
    	{
    		auto start = high_resolution_clock::now(); 
    		int n, m, q;
    		// cin >> n >> m;
    		scanf("%d%d", &n, &m);
    		vi a(n), h(m);
    		// scnarr(a, n);
    		for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    		// scnarr(h, m);
    		for (int i = 0; i < m; ++i) scanf("%d",&h[i]);
    		for(int i = 0; i < n; ++i)
    			a[i]--;
    		// cin >> q;
    		scanf("%d",&q);
    		block = sqrt(n);
    		vector <query> v(q);
     
    		for (int i = 0; i < q; ++i){
    			// cin >> v[i].l >> v[i].r;
    			scanf("%d%d", &v[i].l, &v[i].r);
    			v[i].id = i;
    			--v[i].l, --v[i].r;
    		}
    		sort(all(v), cmp);
    		
     
    		vi fre(m +1, 0), ans(q);
     
    		int curL = 0, curR = 0;
    		
    		for(int i = 0; i < q; ++i){
    			int l = v[i].l, r = v[i].r;
     
    			while(curL < l){
    				fre[a[curL]]--;
    				curL++;
    			}
    			while(curL > l){
    				fre[a[curL -1]]++;
    				curL--;
    			}
     
    			while(curR <= r){
    				fre[a[curR]]++;
    				curR++;
    			}
     
    			while(curR > r +1){
    				fre[a[curR -1]]--;
    				curR--;
    			}
    			int j;
     
    			for(j = l; j <= r; ++j){
    				if(fre[a[j]] != h[a[j]]){
    					break;
    				}
    			}
     
    			if(j == r +1)
    				ans[v[i].id] = 1;
    			else
    				ans[v[i].id] = 0;
    		}
     
    		for(int i = 0; i < q; ++i)
    			printf("%d\n", ans[i]);
     
     		auto stop = high_resolution_clock::now(); 
     		auto duration = duration_cast<milliseconds>(stop - start); 
     		debug(duration.count());
    	}
    	return 0;
    }
     
     
    //Author : Ankit Raj
    //InSearchForMeanings
    //Problem Link :
