#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, arr[1005];
pii sol[1005][1005];
pii solve(int l, int r){
    if(sol[l][r].F != -1) return sol[l][r];
    if(l > r) return {0, 0};
    pii tr = solve(l, r - 1), tl = solve(l + 1, r);
    if(tr.S + arr[r] > tl.S + arr[l]){
        sol[l][r] = {tr.S + arr[r], tr.F};
    } else {
        sol[l][r] = {tl.S + arr[l], tl.F};
    }
    return sol[l][r];
}

int main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) sol[i][j] = {-1, -1};
    }
    pii p = solve(0, n - 1);
    cout << p.F << " " << p.S << endl;
}
