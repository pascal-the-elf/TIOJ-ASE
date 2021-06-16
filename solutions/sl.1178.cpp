#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

pii ch[maxN], points[maxN];
bool inCh[maxN];
int N, x, y, m, m2;

pii operator-(pii a, pii b){
    return {a.F - b.F, a.S - b.S};
}

int operator*(pii a, pii b){
    return a.F * b.S - a.S * b.F;
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> points[i].F >> points[i].S;
    }
    sort(points, points + N);
    for(int i = 0; i < N; i++){
        while(m > 1 && (ch[m - 1] - ch[m - 2]) * (points[i] - ch[m - 1]) <= 0) m--;
        ch[m++] = points[i];
    }
    int bottomsz = m;
    for(int i = N - 2; i >= 0; i--){
        while(m > bottomsz && (ch[m - 1] - ch[m - 2]) * (points[i] - ch[m - 1]) <= 0) m--;
        ch[m++] = points[i];
    }
    //sort(ch, ch + m);
    //m = unique(ch, ch + m) - ch;
    cout << m - 1 << endl;
}

