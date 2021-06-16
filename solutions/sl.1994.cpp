#include <iostream>
#include <vector>
#define vvi vector<vector<int> >
using namespace std;

vvi ans;

vvi get(int l){
    int sz = (1LL << l);
    vvi res(sz);
    for(int i = 0; i < sz; i++) res[i].resize(sz);
    if(!l){
        res[0][0] = 0;
        return res;
    }
    vvi last = get(l - 1);
    vvi lef = last, rig = last;
    for(int i = 0; i < sz/2; i++){
        for(int j = 0; j < sz/2; j++){
            lef[i][j] = last[j][i];
            rig[sz/2 - i - 1][sz/2 - j - 1] = last[j][i];
        }
    }
    int t = (1LL << (2 * l - 2));
    for(int i = 0; i < sz/2; i++){
        for(int j = 0; j < sz/2; j++){
            res[i][j] = lef[i][j];
            res[i][j + sz/2] = rig[i][j] + 3 * t;
            res[i + sz/2][j] = last[i][j] + t;
            res[i + sz/2][j + sz/2] = last[i][j] + 2 * t;
        }
    }
    return res;
}

int N;

int main(){
    cin >> N;
    ans = get(N);
    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < (1 << N); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
