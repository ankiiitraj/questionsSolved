#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
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

const int MOD = 1000000007; 
const int MAXN = 1000005; 

struct Point{
	int x, y;
};

vector<Point> a(1500);

long double area(vector<Point> points){
    long double area = 0.0; 
    int n = points.size();
    int cur = n - 1; 
    for (int i = 0; i < n; i++){ 
        area += (points[cur].x + points[i].x) * (points[cur].y - points[i].y); 
        cur = i;
    }
    return abs(area / 2.0); 
} 
Point p0; 
  
Point nextToTop(stack<Point> &S){ 
    Point p = S.top(); 
    S.pop(); 
    Point res = S.top(); 
    S.push(p); 
    return res; 
} 

void swap(Point &p1, Point &p2){ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 

int distSq(Point p1, Point p2){ 
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); 
} 

int orientation(Point p, Point q, Point r){ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
} 

int compare(const void *vp1, const void *vp2){ 
	Point *p1 = (Point *)vp1; 
	Point *p2 = (Point *)vp2; 
  
   
	int o = orientation(p0, *p1, *p2); 
	if (o == 0) 
		return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 

	return (o == 2)? -1: 1; 
} 
  

long double convexHull(vector<Point> points){ 
   
   	int ymin = points[0].y, min = 0, n = points.size(); 
   	for (int i = 1; i < n; i++){ 
   	int y = points[i].y; 

   	if ((y < ymin) || (ymin == y && 
        points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   	} 
   	swap(points[0], points[min]); 
   
   	p0 = points[0]; 
   	qsort(&points[1], points.size(), sizeof(Point), compare); 
  
  	int m = 1; 
   	for (int i=1; i<n; i++){ 
       while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) 
          i++; 
       points[m] = points[i]; 
       m++;  
   	}
   	if (m < 3) return; 
  	stack<Point> S; 
	S.push(points[0]); 
	S.push(points[1]); 
	S.push(points[2]); 
  
  	for (int i = 3; i < m; i++){ 
      
      
      
	while (orientation(nextToTop(S), S.top(), points[i]) != 2) 
		S.pop(); 
  	S.push(points[i]); 
   	} 
  	vector<Point> res;
  	while (!S.empty()){ 
       Point p = S.top();
       res.push_back(p);
       S.pop(); 
   }
   return area(res);
} 


long double compute_penalty(vi random_idx){
	vector<Point> temp = a;
	int n = temp.size();
	long double penalty = 0;
	for(int i = 0; i < n; ++i){
		Point poi[n - i -1];
		for(int i = 0; i < n; ++i){

		}
		penalty += compute_penalty(temp);
	}
	return penalty;
}


void solve(){
	int n, m, cnt = 0;
	cin >> n;
	vector<Point> res;
	a.resize(n);
	vi random_idx(n);
	for(auto itr: a){
		cin >> itr.x >> itr.y;
		random_idx[cnt] = cnt;
		cnt++;
	}
	cin >> m;

	long double cur_penalty = MOD;

	for(int i = 0; i < 10; ++i){
		random_shuffle(all(random_idx));

		long double penalty = compute_penalty(random_idx);

		if(penalty < cur_penalty and penalty < m){
			cur_penalty = penalty;
			res = random_idx;
		}

	}

	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	
	srand(time(NULL));
		solve();
	return 0;
}





/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/
	