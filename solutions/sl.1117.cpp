#include <iostream>
#include <vector>
using namespace std;

int n, i, a, b;

vector<int> solve(int n, int i){
    vector<int> res;
    res.resize((1 << n));
    if(n == 0){
        res[0] = -1;
        return res;
    }
    int m = 1;
    if(i >= (1LL << (n - 1))){
        m = -1;
        i -= (1LL << (n - 1));
    }
    vector<int> tmp = solve(n - 1, i);
    for(int i = 0; i < (1 << (n - 1)); i++){
        res[i] = tmp[i];
        res[i + (1<<(n - 1))] = m * tmp[i];
    }
    return res;
}

int main(){
    int k;
    while(cin >> n >> k >> a >> b){
        k--;
        vector<int> rr = solve(n, k);
        for(int i = a - 1; i < b; i++){
            if(rr[i] > 0) cout << "+";
            cout << rr[i] << " \n"[i == b - 1];
        }
    }
}
