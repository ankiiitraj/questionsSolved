#include<bits/stdc++.h>
using namespace std;


class singleton
{
    singleton(){}
    int a = 0;
    static singleton s;
public:
    singleton(singleton&o)=delete;
    int getCurrentInd(){
        return a++;
    }
    static singleton &getInstance(){
        return s;
    }
};

singleton singleton::s;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    
    singleton& s = singleton::getInstance();
    singleton& t = singleton::getInstance();
    
    cout << s.getCurrentInd() << endl;
    cout << t.getCurrentInd() << endl;
    cout << s.getCurrentInd() << endl;
    
}







