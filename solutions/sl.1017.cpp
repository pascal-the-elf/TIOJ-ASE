#include <iostream>
using namespace std;
// By S
int T, N;

int main(){
    cin >> T;
    while(T--){
        cin>> N;
        int arr[N], minArr[N], maxArr[N];
        for(int i = 0; i < N; i++){
            scanf("%d", &arr[i]);
        }
        minArr[N-1] = arr[N-1];
        maxArr[0] = arr[0];
        for(int i = 1 ; i < N; i++){
            maxArr[i] = max(arr[i], maxArr[i-1]);
            minArr[N - i - 1] = min(arr[N - i - 1], minArr[N - i]);
        }
        /*
        for(int i = 0 ; i < N; i++){
            cout << minArr[i] << " ";
        }
        cout << endl;
        for(int i = 0 ; i < N; i++){
            cout << maxArr[i] << " ";
        }
        cout << endl;
        */
        int ans = 0;
        for(int i = 1; i < N-1; i++){
            if(arr[i] > maxArr[i-1] && arr[i] < minArr[i + 1]) ans++;
        }
        cout << ans << endl;
    }
}
