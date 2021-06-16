#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 25, maxM = 1e8 + 10;

int m, n, arr[maxN];

bool isWin[maxM];

/*
First two subtasks: O(mn)
Third subtask: n is small but a is large, I think O(mn) with optimization might be able to pass it? <- Yes it can
Fourth subtask: Conjecture that it will devolve into sequence of 0101010.... after some number of steps
                Or has a set pattern. Either way, it will stabilize
*/

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int cnt = 0;
    for(int i = 0; i <= m; i++){
        if(!isWin[i]){
            for(int j = 0; j < n && arr[j] + i <= m; j++) isWin[i + arr[j]] = true;
        } else cnt++;
        //cout << isWin[i];
    }
    cout << cnt << endl;

}
