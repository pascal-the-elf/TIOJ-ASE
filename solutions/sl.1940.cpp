#include <iostream>
#include <vector>
using namespace std;

const int maxN = 129;

int sg[maxN], k, n;

inline int getMex(vector<int> v){
    bool has[maxN + 10];
    for(int i = 0; i <= maxN; i++) has[i] = 0;
    for(int x : v) has[x] = true;
    for(int i = 0; i <= maxN + 1; i++){
        if(!has[i]) return i;
    }
}

string getBin(int x){
    string s = "";
    for(int i = 7; i >= 0; i--){
        s += (x & (1 << i)) > 0 ? '1' : '0';
    }
    return s;
}

int solve(int x){
    if(x == 1) return 1;
    if(!x) return 0;
    while(x % 2) x /= 2;
    if(x == 2) return 0;
    else return x / 2;
}

int main(){
    sg[0] = 0;

    //cout << "sg[" << getBin(0) << "] = " << sg[0] << endl;
    for(int i = 1; i <= 128; i++){
        vector<int> vec;
        for(int t = 1; t <= max(1, i / 2); t++){
            vec.push_back(sg[i - t]);
            //cout << "Pushing " << sg[i - t] << endl;
        }
        sg[i] = getMex(vec);
        //if(solve(i) != sg[i]){
        //    cout << "solve(" << i << ") = " << solve(i) << endl;
        //    cout << "sg[" << getBin(i) << "] = " << sg[i] << endl;
        //}
    }
    int n, k;
    cin >> k >> n;
    if(k == 1) cout << n << endl;
    else {
        //if(n <= 128) cout << sg[n] << endl;
        cout << solve(n) << endl;
    }
}
