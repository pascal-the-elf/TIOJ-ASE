#pragma GCC optimize ("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked
#define pc putchar_unlocked

using namespace std;

int n, m, q, a, b;
pii vec[(int)(1e6) + 5];

inline  int sscan()
{register  int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0')
    {
n=n*10+c-'0';
c=gc();
    }
return n;
}
inline void pY(){
    pc('y');
    pc('e');
    pc('s');
    pc('\n');
}

inline void pN(){
    pc('n');
    pc('o');
    pc('\n');
}

int main(){
    //ericxiao;
    n = sscan();
    m = sscan();
    q = sscan();
    for(int i = 0; i < m; ++i){
        a = sscan();
        b = sscan();
        if(a > b) swap(a, b);
        vec[i] = {a, b};
    }
    sort(vec, vec + m);
    pii p;
    for(int i = 0; i < q; ++i){
        a = sscan();
        b = sscan();
        if(a > b) swap(a, b);
        p = {a, b};
        if(*lower_bound(vec, vec + m, p) == p){
            pY();
        } else {
            pN();
        }
    }
}


