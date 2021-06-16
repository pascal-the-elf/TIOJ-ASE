#include <iostream>
#include <vector>
using namespace std;

int t, n;

inline int solve(int N){
    vector<int> choose;
    vector<int>().swap(choose);
    int score = 0, _t;
    for(int i = 1; i <= N; i++){
        _t = 0;
        for(int x : choose) if(!(i % x)) _t++;
        _t -= (N/i - 1);
        //cout << "Or: " << N/i - 1 << endl;
        if(_t < 0){
            //cout << "putting " << i << " in " << endl;
            choose.push_back(i);
            score -= _t;
        }
    }
    //cout << "Score = " << score << endl;
    return score;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
}
