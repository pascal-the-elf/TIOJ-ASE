#include <iostream>
#include <math.h>
using namespace std;

const int maxN = 3e6 + 226;

long double prelog[maxN];
int presign[maxN], zcnt[maxN], N, Q, x, l, r, sgn;

int main(){
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x);
        presign[i] = presign[i - 1] + (x < 0);
        if(x < 0) x = -x;
        if(!x){
            zcnt[i]++;
            zcnt[i] += zcnt[i - 1];
            prelog[i] = prelog[i - 1];
        } else {
            zcnt[i] = zcnt[i - 1];
            prelog[i] = prelog[i - 1] + log10(x);
        }
    }
    while(Q--){
        scanf("%d%d", &l, &r);
        l++;
        if((zcnt[r] - zcnt[l - 1]) > 0){
            printf("0.0\n");
            continue;
        }
        if((presign[r] - presign[l - 1]) % 2) sgn = -1;
        else sgn = 1;
        int e = floor(prelog[r] - prelog[l - 1]);
        long double a = prelog[r] - prelog[l - 1] - e;
        long double ans = pow((long double)10, a);
        printf("%.10LfE+%d\n", ans * sgn, e);
    }
}
