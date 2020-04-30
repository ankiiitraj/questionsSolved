#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// & 0 1 a A
// 0 0 0 0 0
// 1 0 1 a A
// a 0 a a 0
// A 0 A 0 A

// | 0 1 a A
// 0 0 1 a A
// 1 1 1 1 1
// a a 1 a 1
// A A 1 1 A

// ^ 0 1 a A
// 0 0 1 a A
// 1 1 0 A a
// a a A 0 1
// A A a 1 0

size_t sum(const vector<size_t, 4>& a)
{
    return accumulate(a.begin(), a.end(), 0u);
}

vector<size_t, 4> prob(const string& s)
{
    if (s.empty()) { return {0,0,0,0}; }
    
    // 0 1 a A
    vector<size_t, 4> p = {1, 1, 1, 1};
    
    for (char c : s) {
        switch (c) {
            case '&':
            {
                p = { sum(p) + 3 * p[0] + p[2] + p[3],
                    p[1],
                    p[1] + 2*p[2],
                    p[1] + 2*p[3]
                };
                break;
            }
            case '|':
            {
                p = { p[0],
                      sum(p) + 3 * p[1] + p[2] + p[3],
                    p[0] + 2*p[2],
                    p[0] + 2*p[3]
                };
                break;
            }
            case '^':
            {
                p = { sum(p),
                      sum(p),
                      sum(p),
                      sum(p)
                };
                // p = {1, 1, 1, 1}; // equivalent
                break;
            }
            default:break;
        }
    }
    
    return p;    
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
    for (auto s : {"#&#", "#|#", "#^#", "#|#|#|#", "#^#|#^#&#|#"}) {
        auto [zero, one, a, A] = prob(s);
        
        cout << s << ":\t" << zero << " " <<  one << " " << a << " " << A << endl;
    }
}	