#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
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
/*
	----------------------------------------------------------------------
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

int minVal(int x, int y) { return (x < y)? x: y; }  
int getMid(int s, int e) { return s + (e -s)/2; }  
  
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)  
{  
    // If segment of this node is a part  
    // of given range, then return  
    // the min of the segment  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    // If segment of this node 
    // is outside the given range  
    if (se < qs || ss > qe)  
        return INT_MAX;  
  
    // If a part of this segment 
    // overlaps with the given range  
    int mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
  
// Return minimum of elements in range 
// from index qs (query start) to  
// qe (query end). It mainly uses RMQUtil()  
int RMQ(int *st, int n, int qs, int qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
  
// A recursive function that constructs 
// Segment Tree for array[ss..se].  
// si is index of current node in segment tree st  
int constructSTUtil(int arr[], int ss, int se, int *st, int ssi){  
    // If there is one element in array, 
    // store it in current node of  
    // segment tree and return  
    if (ss == se)  
    {  
        st[ssi] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements,  
    // then recur for left and right subtrees  
    // and store the minimum of two values in this node  
    int mid = getMid(ss, se);  
    st[ssi] = minVal(constructSTUtil(arr, ss, mid, st, ssi*2+1),  
                    constructSTUtil(arr, mid+1, se, st, ssi*2+2));  
    return st[ssi];  
}  
  
/* Function to construct segment tree  
from given array. This function allocates 
memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
int *constructST(int arr[], int n)  
{  
    // Allocate memory for segment tree  
  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    int *st = new int[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
} 


void solve(){
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);

	map<int, vi> m;
	for(int i = 0; i < n; ++i){
		m[a[i]].push_back(i);
	}

	set<int> s;
	vi lens(n +1, 0);
	for(int i = 1; i <= n; ++i){
		if(s.empty()){
			for(auto itr: m[i]){
				s.insert(itr);
			}
			if(m[i].size() > 0){
				lens[i] = n;
			}
			continue;
		}
		for(auto itr: m[i]){
			auto idx = s.lower_bound(itr);
			int dist;
			if(idx == s.end()){
				dist = n -1 - (*s.rbegin()); 
			}else if(idx == s.begin()){
				dist = *idx;
			}else{
				dist = (*idx) - (*(--idx)) -1;
			}
			lens[i] = max(lens[i], dist);
		}
		for(auto itr: m[i]){
			s.insert(itr);
		}
	}

	int arr[n +1] = {0};
	for(int i = 1; i <= n; ++i){
		arr[i] = lens[i];
	}

	int *st = constructST(arr, n +1);  


	string res;
	for(int i = 1; i <= n; ++i){
		if(RMQ(st, n +1, 1, n - i +1) >= i){
			res += '1';
		}else{
			res += '0';
		}
	}
	cout << res << endl;
	// for(int i = 1; i <= n; ++i)
	// 	cout << lens[i] << " ";
	// cout << endl;

	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
		solve();
	return 0;
}


//Author : Ankit Raj
//Problem Link :

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
