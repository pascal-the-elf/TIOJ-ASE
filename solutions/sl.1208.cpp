#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e4 + 10, INF = 2e8 + 10;

int N, K, pre[maxN], H;

vector<int> mergeSort(int l, int r, int lim, int &howmany){ //howmany that pre[r] <= lim + pre[l]
    //cout << "Running (" << l << ", " << r << ")" << endl;
    vector<int> res = vector<int>();
    if(r - l <= 1){
        for(int i = l; i < r; i++) res.push_back(pre[i]);
        //cout << "From " << l << " to " << r << ": "; for(int x : res) cout << x << " ";
        //cout << endl;
        howmany = 0;
        return res;
    }
    int lC = 0, rC = 0, m = (l + r) / 2;
    res.resize(r - l);
    vector<int> L = mergeSort(l, m, lim, lC), R = mergeSort(m, r, lim, rC);
    howmany = lC + rC;
    int lP = 0;
    for(int pR : R){
        while(lP < L.size() && L[lP] + lim < pR) lP++;
        howmany += lP;
    }
    merge(L.begin(), L.end(), R.begin(), R.end(), res.begin());
    //cout << "From " << l << " to " << r << ": "; for(int x : res) cout << x << " ";
    //cout << endl;
    return res;
}

int main(){
    ericxiao;
    while(cin >> N >> K){
        if(!N) return 0;
        for(int i = 1; i <= N; i++){
            cin >> pre[i];
            if(i) pre[i] += pre[i - 1];
        }
        mergeSort(0, N + 1, 9, H);
        int l = -INF, r = INF, mid;
        while(l + 1 < r){
            mid = (l + r) / 2;
            mergeSort(0, N + 1, mid, H);
            //H: how many are >= than mid
            //cout << " l = " << l << ", r = " << r << endl;
            //cout << H << " segs larger than " << mid << endl;
            if(H >= K){
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << r << endl;
    }

}
