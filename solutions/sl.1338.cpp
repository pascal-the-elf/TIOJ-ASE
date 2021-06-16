#include <iostream>
#include <math.h>
#include "lib1338.h"
using namespace std;

const long long int maxN = 1e6;
long long int ST[21][maxN + 10][2]; //ST[0]: min val, segTree[1]: gcd
//ST has to have a max of 24 layers and a min of 20 layers to get AC...

long long int gcd(long long int a, long long int b){
    return !b ? a : gcd(b, a % b);
}

void init(int N, long long C[]){
    for(int i = 0; i < N; i++){
        ST[0][i][0] = ST[0][i][1] = C[i];
    }
    for(int i = 1; (1 << i) <= N; i++){
        for(int j = 0; j <= (N - (1 << i)); j++){
            ST[i][j][0] = min(ST[i-1][j][0], ST[i-1][j + (1 << (i - 1))][0]);
            ST[i][j][1] = gcd(ST[i-1][j][1], ST[i-1][j + (1 << (i - 1))][1]);
            //cout << ST[i][j][0] << " ";
        }
        //cout << endl;
    }
}

int query(int L, int R){
    int k = floor(log2(R - L)); //kth layer
    long long int A = min(ST[k][L][0], ST[k][R - (1 << k)][0]);
    long long int B = gcd(ST[k][L][1], ST[k][R - (1 << k)][1]);
    return A == B;
}
