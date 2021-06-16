#include <iostream>
#include <map>
#include <numeric>
#define int long long int
using namespace std;

const int maxN = 5e4 + 10;

struct DSU{
    int N, cc, dsu[maxN];
    DSU(){}
    DSU(int n){
        N = cc = n;
        iota(dsu, dsu + N, 0);
    }
    void Flat(int x){
        if(x == dsu[x]) return;
        Flat(dsu[x]);
        dsu[x] = dsu[dsu[x]];
    }
    void Merge(int a, int b){
        Flat(a);
        Flat(b);
        if(dsu[a] == dsu[b]) return;
        dsu[dsu[a]] = dsu[b];
        cc--;
    }
} dsu;

int hsh(int i, int j){
    return 1e5 * i + j;
}

map<int, int> coords;

int N, x, y, dy[5] = {2, 1, 0, -1, -2}, dx[5] = {2, 1, 0, -1, -2};

signed main(){
    cin >> x >> y >> N;
    dsu = DSU(N);
    for(int iiii = 0; iiii < N; iiii++){
        cin >> x >> y;
        for(int a = 0; a < 5; a++){
            for(int b = 0; b < 5; b++){
                if(coords.count(hsh(x + dx[a], y + dy[b]))){
                    dsu.Merge(iiii, coords[hsh(x + dx[a], y + dy[b])]);
                }
            }
        }
        coords[hsh(x, y)] = iiii;
    }
    cout << dsu.cc << endl;
}
