#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


const int MAXN = 1LL << 20;
bool canDo[MAXN + 10], newDo[MAXN + 10];
int N, x, mv;

int main(){
    while(cin >> N){
        if(!N) return 0;
        mv = 0;
        for(int i = 0; i < MAXN; i++){
            canDo[i] = false;
            newDo[i] = false;
        }
        canDo[0] = true;
        newDo[0] = true;
        for(int i = 0; i < N; i++){
            cin >> x;
            for(int i = 0; i < MAXN; i++){
                if(canDo[i]){
                    //cout << "canDo[" << (i ^ x) << "] = true" << endl;
                    newDo[i ^ x] = true;
                    mv = max(i ^ x, mv);
                }
            }
            for(int i = 0; i < MAXN; i++) canDo[i] = newDo[i];
        }
        cout << mv << endl;
    }
}
