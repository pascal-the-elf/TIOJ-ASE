#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 10;

int N, x, lis[maxN], lisan[maxN], arr[maxN];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        lisan[i] = arr[i];
    }
    sort(lisan, lisan + N);
    int sz = unique(lisan, lisan + N) - lisan;
    for(int i = 0; i < N; i++){
        arr[i] = lower_bound(lisan, lisan + sz, arr[i]) - lisan;
    }
    fill(lis, lis + maxN, maxN);
    for(int i = 0; i < N; i++){
        *lower_bound(lis, lis + N, arr[i]) = arr[i];
    }
    cout << lower_bound(lis, lis + N, maxN) - lis << endl;
}
