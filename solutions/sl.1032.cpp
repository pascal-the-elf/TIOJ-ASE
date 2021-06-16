#include <iostream>
#define int long long int
using namespace std;

int N, M, k, a, b, c, vals[100005];



int Hash(int a, int b){
    return ((int)(1e7 + 9) * a + b) % (int)(1e9 + 7);
}

signed main(){
    cin >> N >> M;
    fill(vals, vals + N + 1, 0);
    while(M--){
        cin >> k;
        if(k == 0){
            cin >> a >> b;
            if(a > b) swap(a, b);
            vals[a] -= Hash(a, b);
            vals[b] += Hash(a, b);
        } else if(k == 1){
            cin >> a >> b;
            if(a > b) swap(a, b);
            vals[a] += Hash(a, b);
            vals[b] -= Hash(a, b);
        } else if(k == 2){
            cin >> c;
            int sum = 0;
            while(c--){
                cin >> a;
                sum += vals[a];
            }
            cout << (sum == 0) << endl;
        }
    }
}
