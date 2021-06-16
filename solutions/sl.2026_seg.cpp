#include <iostream>
using namespace std;

const int maxN = (1 << 20);

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

struct ZCK{
    int sum[maxN * 2 + 10];
    ZCK(){}
    void modify(int p){
        for(p += maxN; p; p >>= 1) sum[p]++;
    }
    int getKth(int k){
        int l = 0, r = maxN, pos = 1;
        while(l + 1 < r){
            if(sum[pos * 2] >= k){
                r = (l + r) / 2;
                pos = pos * 2;
            } else {
                l = (l + r) / 2;
                k -= sum[pos * 2];
                pos = pos * 2 + 1;
            }
        }
        return l;
    }
} seg;

int Q, c, x, sz;

int main(){
    input(Q);
    while(Q--){
        input(c);
        if(c == 1){
            input(x);
            seg.modify(x);
            sz++;
        } else if(c == 2){
            cout << seg.getKth((sz + 1) / 2) << '\n';
        }
    }
}
