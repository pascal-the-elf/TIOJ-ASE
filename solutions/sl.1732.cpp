#include <iostream>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int N, arr[maxN];

signed main(){
    ericxiao;
    while(cin >> N){
        for(int i = 0; i < N; i++) cin >> arr[i];
        sort(arr, arr + N);
        int mid = arr[N / 2], s = 0;
        for(int i = 0; i < N; i++){
            s += (mid > arr[i] ? mid - arr[i] : arr[i] - mid);
        }
        cout << s << '\n';
    }
}
