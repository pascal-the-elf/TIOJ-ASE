#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 100010;

int n, arr[maxN], cf, pr;

signed main(){
    ericxiao;
    while(cin >> n){
        if(!n) return 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        cf = 1 + arr[0] + arr[n - 1];
        for(int i = 1; i < n; i++){
            cf += arr[i];
        }
        cout << cf << endl;
    }
}
