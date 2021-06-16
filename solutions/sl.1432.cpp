#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1226, INF = 1e9;

int n, w, arr[maxN];

bool can(int maxCost){
    int currentSum = 0, pieces = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxCost) return false;
        if(currentSum + arr[i] > maxCost){
            currentSum = arr[i];
            pieces++;
        } else {
            currentSum += arr[i];
        }
    }
    return pieces <= w;
}

int main(){
    ericxiao;
    while(cin >> n >> w){
        if(!n && !w) return 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        int l = 0, r = INF, m;
        while(l + 1 < r){
            m = (l + r) / 2;
            if(can(m)){
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << '\n';
    }
}
