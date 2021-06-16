#include <iostream>
#include <vector>
using namespace std;

struct BIT{
    int N;
    vector<int> bit;
    BIT(){}
    BIT(int n): N(n){
        bit.resize(N + 1);
        fill(bit.begin(), bit.end(), 0);
    }
    inline void add(int p, int x){
        for(int i = p; i <= N; i += i & -i) bit[i] += x;
    }
    inline int get(int p){
        int res = 0;
        for(int i = p; i; i -= i & -i) res += bit[i];
        return res;
    }
};

BIT vSum, vCnt, hSum, hCnt;
int N, M, x;

int main(){
    cin >> N >> M;
    vSum = BIT(N);
    vCnt = BIT(N);
    hSum = BIT(M);
    hCnt = BIT(M);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> x;
            vSum.add(i, x * i);
            vCnt.add(i, x);
            hSum.add(j, x * j);
            hCnt.add(j, x);
        }
    }
    int minVal = 214748367, minI, minJ, t;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            t = vCnt.get(i - 1) * i - vSum.get(i - 1) + vSum.get(N) - vSum.get(i) - (vCnt.get(N) - vCnt.get(i)) * i;
            t += hCnt.get(j - 1) * j - hSum.get(j - 1) + hSum.get(M) - hSum.get(j) - (hCnt.get(M) - hCnt.get(j)) * j;
            //cout << "i = " << i << ", j = " << j << ", t = " << t << endl;
            if(t < minVal){
                minVal = t;
                minI = i;
                minJ = j;
            }
        }
    }
    cout << minI << " " << minJ << '\n';
}
