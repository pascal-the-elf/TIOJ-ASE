#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<int> vec;

bool check(vector<int> v){
    vector<int> cnt;
    cnt.resize(N);
    int s = 0;
    for(int i : v){
        s = (s + i) % N;
        cnt[s]++;
        if(cnt[s] > 1) return false;
    }
    return true;
}

int main(){
    cin >> N;
    if(N == 1){
        cout << "Yes\n1\n";
        return 0;
    }
    if(N % 2){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> vv;
    vv.resize(N);
    vec.resize(N);
    int cnt = N;
    for(int i = 0; i < N; i += 2){
        vv[i] = cnt--;
    }
    cnt = 1;
    for(int i = 1; i < N; i += 2){
        vv[i] = cnt++;
    }
    vec[0] = 0;
    cout << N;
    for(int i = 1; i < N; i++){
        //cout << " " << vv[i];
        vec[i] = (vv[i] - vv[i - 1] + N) % N;
    }
    //cout << endl;
    for(int i = 1; i < N; i++){
        cout << " " << vec[i];
    }
    //cout << endl;
    //cout << "CHECK: " << check(vec) << endl;
}
