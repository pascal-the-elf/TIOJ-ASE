#include <iostream>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, arr[3];

signed main(){
    ericxiao;
    cin >> N;
    while(N--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        if(arr[0] <= 0 || (arr[0] * arr[0] != arr[2] * arr[2] - arr[1] * arr[1])){
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
}
