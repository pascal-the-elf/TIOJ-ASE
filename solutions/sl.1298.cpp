#include <iostream>
using namespace std;

int N, wins, mV = 201, MV = -1, sum, x;

inline int abs(int x){
    return (x > 0 ? x : -x);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        if(x > 0) wins++;
        x = abs(x);
        sum += x;
        mV = min(x, mV);
        MV = max(x, MV);
    }
    printf("Average time: %.3f sec(s).\n", (sum - mV - MV) * 1.0 / (N - 2));
    printf("Winning rate: %.3f %%.\n", wins * 100.0 / N);
}
