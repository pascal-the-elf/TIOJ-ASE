#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, x;

int main(){
    ericxiao;
    while(cin >> N){
        for(int i = 1; i <= N; i++){
            cin >> x;
            cout << i << " \n"[i == N];
        }
    }
}
