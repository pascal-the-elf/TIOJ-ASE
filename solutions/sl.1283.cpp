#include <iostream>
#include <deque>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5;

struct Line{
    int h, l, r;
    Line(){}
    Line(int h, int l, int r): h(h), l(l), r(r){}
} line, ups[maxN], downs[maxN];

struct Seg{
    int l, r, id;
    /*
        l, r: from 0 ~ M - 1, bottom
        id: 0 ~ N - 1, top
    */
    Seg(){}
    Seg(int l, int r, int id): l(l), r(r), id(id){}
} current;

inline int Abs(int x){
    return (x < 0) ? -x : x;
}

inline int area(Line u, Line d){
    return (u.r - d.l) * (d.h - u.h); //Don't ABS here :(
}

deque<Seg> trans;

int N, M, r, d, cx, cy;

signed main(){
    ericxiao;
    cin >> N;
    N /= 2;
    cx = cy = 0;
    for(int i = 0; i < N; i++){ // - | - |
        cin >> r >> d;
        ups[i] = Line(cy, cx, cx + r);
        cx += r;
        cy += d;
    }
    cin >> M;
    M /= 2;
    cx = cy = 0;
    for(int i = 0; i < M; i++){ // | - | - | - | -
        cin >> d >> r;
        downs[i] = Line(cy + d, cx, cx + r);
        cx += r;
        cy += d;
    }
    for(int i = 0; i < N; i++){
        while(trans.size()){
            int id = trans.back().id;
            if(area(ups[id], downs[trans.back().l]) <= area(ups[i], downs[trans.back().l])) trans.pop_back();
            else break;
        }
        if(trans.size()){
            int id = trans.back().id, L = trans.back().l, R = trans.back().r, MID;
            if(area(ups[id], downs[M - 1]) > area(ups[i], downs[M - 1])) continue;
            while(L + 1 < R){
                MID = (L + R) / 2;
                if(area(ups[id], downs[MID]) <= area(ups[i], downs[MID])) R = MID;
                else L = MID;
            }
            trans.back().r = L;
            trans.push_back(Seg(L, M, i));
        } else {
            trans.push_back(Seg(0, M, i));
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        while(trans.size() && trans.front().r <= i) trans.pop_front();
        ans = max(ans, area(ups[trans.front().id], downs[i]));
    }
    cout << ans << endl;
}
