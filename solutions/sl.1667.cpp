#include <iostream>
using namespace std;

const int maxN = 110;

int n, arr[maxN];

int main(){
    while(cin >> n){
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            for(int j = 0; j < i; j++){
                ans += (arr[j] > arr[i]);
            }
        }
        cout << ans << endl;
    }
}
