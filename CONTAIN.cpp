#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
using namespace std;

struct Point 
{ 
  int x, y; 
}; 

Point p0; 

int lies(int n, int *vx, int *vy, float xx, float yy)
{
  int i, j, c = 0;
  for (i = 0, j = n-1; i < n; j = i++) {
    if ( ((vy[i]>yy) != (vy[j]>yy)) &&
   (xx < (vx[j]-vx[i]) * (yy-vy[i]) / (vy[j]-vy[i]) + vx[i]) )
       c = !c;
  }
  return c;
}

Point ntt(stack<Point> &S) 
{ 
  Point p = S.top(); 
  S.pop(); 
  Point res = S.top(); 
  S.push(p); 
  return res; 
} 

void swap(Point &p1, Point &p2) 
{ 
  Point temp = p1; 
  p1 = p2; 
  p2 = temp; 
} 

int distsquare(Point p1, Point p2) 
{ 
  return (p1.x - p2.x)*(p1.x - p2.x) + 
    (p1.y - p2.y)*(p1.y - p2.y); 
} 

int orientation(Point p, Point q, Point r) 
{ 
  int val = (q.y - p.y) * (r.x - q.x) - 
      (q.x - p.x) * (r.y - q.y); 

  if (val == 0) return 0; 
  return (val > 0)? 1: 2; 
} 

int compare(const void *vp1, const void *vp2) 
{ 
  Point *p1 = (Point *)vp1; 
  Point *p2 = (Point *)vp2; 


  int o = orientation(p0, *p1, *p2); 
  if (o == 0) 
    return (distsquare(p0, *p2) >= distsquare(p0, *p1))? -1 : 1; 
  return (o == 2)? -1: 1; 
} 

vector<Point> convexHull(vector<Point> points, int n) 
{ 

  int ymin = points[0].y, min = 0; 
  for (int i = 1; i < n; i++) 
  { 
    int y = points[i].y; 
    if ((y < ymin) || (ymin == y && 
      points[i].x < points[min].x)) 
      ymin = points[i].y, min = i; 
  } 
  swap(points[0], points[min]); 
  p0 = points[0]; 
  qsort(&points[1], n-1, sizeof(Point), compare); 

  int m = 1; 
  for (int i=1; i<n; i++) 
  { 
    
    
    while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) 
      i++; 
    points[m] = points[i]; 
    m++; 
  } 

  stack<Point> S; 
  S.push(points[0]); 
  S.push(points[1]); 
  S.push(points[2]); 


    for (int i = 3; i < m; i++) 
    { 
      while (orientation(ntt(S), S.top(), points[i]) != 2) 
        S.pop(); 
      S.push(points[i]); 
    } 

    vector<Point> ans;
  while (!S.empty()) 
  { 
    Point p = S.top();
    ans.push_back({p.x, p.y}); 
    // cout << "(" << p.x << ", " << p.y <<")" << " "; 
    S.pop(); 
  } 
  return ans;
} 



int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("ip.txt", "r", stdin);
  freopen("op.txt", "w", stdout);
#endif
  int t; cin >> t; while(t--)
  {
    int n, q, x, y;
    cin >> n >> q;
    vector<Point> points(n), ptemp;
    for(int i = 0; i < n; ++i)
      cin >> x >> y, points[i] = {x, y};
    
    vector<vector<Point>> hulls;
    vector<Point> temp;
    int count = n;
    while(count > 0){
      if(count < 3){
        break;
      }
      temp = convexHull(points, points.size());
      hulls.push_back(temp);
      
      ptemp = points;
      points.clear();
      for(int j = 0; j < ptemp.size(); ++j){
        int flag = 0;
        for(int i = 0; i < temp.size(); ++i){
          if(ptemp[j].x == temp[i].x and ptemp[j].y == temp[i].y){
            flag = 1;
            break;
          }
        }
        if(!flag){
          points.push_back(ptemp[j]);
        }
      }
      count -= temp.size();
    }

    while(q--){
      int res = 0;
      cin >> x >> y;
      for(int i = 0; i < hulls.size(); ++i)
      {
        int vx[hulls[i].size()], vy[hulls[i].size()];
        for(int j = 0; j < hulls[i].size(); ++j){
          vx[j] = hulls[i][j].x;
          vy[j] = hulls[i][j].y;
        }
        int ans = lies(hulls[i].size(), vx, vy, x, y);
        if(ans){
          res++;
        }
      }
        cout << res << endl;
    }

  }
  return 0;
}





  