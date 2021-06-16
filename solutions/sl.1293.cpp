#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int INF = 1e18, maxN = 1e5 + 10;

inline int Abs(int x){
    return (x < 0) ? -x : x;
}

struct Obj{
    int x, y, t;
    Obj(){}
    Obj(int x, int y, int t): x(x), y(y), t(t){}
    int dist(int X, int Y){
        return t * max(Abs(x - X), Abs(y - Y));
    }
} objs[maxN];


int X, Y, N, T, total, ct;
vector<pii> xs, ys;
vector<int> posX, posY;

inline int getDist(int X, int Y){
    int r = 0;
    for(int i = 0; i < N; i++) r += objs[i].dist(X, Y);
    return r;
}

signed main(){
    ericxiao;
	while(cin >> N){
        xs.clear();
        ys.clear();
        posX.clear();
        posY.clear();
        total = 0;
        for(int i = 0; i < N; i++){
            cin >> X >> Y >> T;
            objs[i] = Obj(X, Y, T);
            total += T;
            xs.emplace_back(X - Y, T);
            ys.emplace_back(X + Y, T);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        ct = 0;
        for(int i = 0; i < N; i++){
            ct += xs[i].S;
            if(ct * 2 >= total){
                posX.push_back(xs[i].F);
                posX.push_back(xs[i].F + 1);
                posX.push_back(xs[i].F - 1);
                break;
            }
        }
        ct = 0;
        for(int i = 0; i < N; i++){
            ct += ys[i].S;
            if(ct * 2 >= total){
                posY.push_back(ys[i].F);
                posY.push_back(ys[i].F + 1);
                posY.push_back(ys[i].F - 1);
                break;
            }
        }
        /*
        cout << "S:" << endl;
        for(int x : posX) cout << x << " ";
        cout << endl;
        cout << "M:" << endl;
        for(int y : posY) cout << y << " ";
        cout << endl;
        */
        pii ans = {INF, INF};
        int curDist = INF;
        for(int x : posX){
            for(int y : posY){
                if((x & 1) != (y & 1)) continue;
                int d = getDist((x + y) / 2, (y - x) / 2);
                if(d < curDist){
                    curDist = d;
                    ans = {(x + y) / 2, (y - x) / 2};
                } else if(d == curDist){
                    ans = min(ans, {(x + y) / 2, (y - x) / 2});
                }
            }
        }
        cout << ans.F << " " << ans.S << endl;
	}
}
