#include <iostream>
#pragma GCC optimize ("O3")
#include <algorithm>
#define int short
using namespace std;

int N;

signed main(){
    cin >> N;
    int arr[N + 1];
    for(int i = 0 ; i < N; i++){
        scanf("%hd", &arr[i]);
    }
    sort(arr, arr + N);
    for(int i = 1; i < N; i++){
        if(arr[i] - arr[i-1] != 1){
            printf("%hd %hd no\n", arr[0], arr[N-1]);
            return 0;
        }
    }
    printf("%hd %hd yes\n", arr[0], arr[N-1]);
}
