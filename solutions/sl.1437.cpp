#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);
using namespace std;

const int maxN = 151;

int x, N, cm = -1, nm;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        nm = 0;
        for(int j = 0; j < N; j++){
            cin >> x;
            nm = max(nm, x);
            if(cm < x){
                cout << "(" << j << "," << i << ")\n";
            }
        }
        cm = nm;
    }
}
