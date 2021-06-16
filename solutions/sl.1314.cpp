#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

int T, arr[3];

signed main(){
    cin >> T;
    while(T--){
        cin >> arr[0] >> arr[1] >> arr[2];
        if(arr[0] <= 0 || arr[1] <= 0 || arr[2] <= 0){
            cout << "no\n";
            continue;
        }
        sort(arr, arr + 3);
        cout << (arr[0] * arr[0] == (arr[2] + arr[1]) * (arr[2] - arr[1]) ? "yes\n" : "no\n");
    }
}
