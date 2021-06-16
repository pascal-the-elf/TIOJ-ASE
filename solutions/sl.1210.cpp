#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e4 + 10;

int degs[maxN], n;

int main(){
    ericxiao;
    while(cin >> n){
        if(!n) return 0;
        for(int i = 0; i < n; i++) cin >> degs[i];
        sort(degs, degs + n, greater<int>());
        bool can = true;
        //for(int j = 0; j < n; j++) cout << degs[j] << " \n"[j == n - 1];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n && degs[i]; j++){
                if(degs[j]){
                    degs[i]--;
                    degs[j]--;
                }
            }
            if(degs[i] > 0){
                can = false;
                break;
            }
            if(i < n - 1)
                sort(degs + i + 1, degs + n, greater<int>());
        }
        if(can){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
