#include <iostream>
using namespace std;

const int maxN = 22625 * (1e3), INF = 5e5;

int arr[maxN], d[maxN], N;

int main(){
    cin >> N;
    arr[0] = INF;
    for(int i = 0; i < N; i++){
        cin >> arr[2 * i + 1];
        arr[2 * i + 2] = INF;
    }
    //for(int i = 0; i < 2 * N + 1; i++) cout << arr[i] << " \n"[i == 2 * N];
    //cout << endl;
    int ans = 0;
    for(int i = 0, l = 0, r = -1; i < 2 * N + 1; i++){
        int k = (i > r ? 1 : min(d[(r + l) - i], r - i + 1));
        while(i + k < 2 * N + 1 && 0 <= i - k && arr[i + k] == arr[i - k]) k++;
        d[i] = k--;
        if(i + k > r){
            r = i + k;
            l = i - k;
        }
        ans = max(ans, d[i] - 2);
        //cout << "d[" << i << "] = " << d[i] << endl;
    }
    cout << ans << '\n';
}
