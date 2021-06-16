#include <iostream>
using namespace std;

const int maxN = 1e4 + 10;

int N, K, a[maxN], b[maxN], delta[maxN], rt, ans;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
        b[i]--;
    }
    for(int i = 0; i <= N - K; i++){
        rt = (rt + delta[i] + 9) % 9;
        a[i] = (a[i] + rt + 9) % 9;
        //cout << "For i = " << i << ", a[" << i << "] = " << a[i] << ", and b[" << i << "] = " << b[i] << endl;
        ans += (b[i] - a[i] + 9) % 9;
        rt += (b[i] - a[i] + 9) % 9;
        delta[i + K] -= (b[i] - a[i] + 9) % 9;
        a[i] = b[i];
    }
    for(int i = N - K + 1; i < N; i++){
        rt = (rt + delta[i] + 9) % 9;
        a[i] = (a[i] + rt + 9) % 9;
        //cout << "For i = " << i << ", a[" << i << "] = " << a[i] << ", and b[" << i << "] = " << b[i] << endl;
    }
    /*
    for(int i = 0; i <= N; i++){
        cout << delta[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < N; i++) if(a[i] != b[i]){
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;
}
