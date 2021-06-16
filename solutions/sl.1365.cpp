#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int bit[maxN], N;
long long int ans;
pii cars[maxN];

void modify(int p){
    for(; p < maxN; p += (p & -p)) bit[p]++;
}

int query(int p){
    if(p <= 0) return 0;
    int r = 0;
    for(; p; p -= (p & -p)) r += bit[p];
    return r;
}

int main(){
    ericxiao;
    while(cin >> N){
        ans = 0;
        for(int i = 0; i < N; i++){
            cin >> cars[i].F >> cars[i].S;
            cars[i].S++;
        }
        sort(cars, cars + N, greater<pii>());
        fill(bit, bit + maxN, 0);
        for(int i = 0; i < N; i++){
            ans += query(cars[i].S - 1);
            modify(cars[i].S);
        }
        cout << ans << endl;
    }
}
