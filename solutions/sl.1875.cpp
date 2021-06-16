#pragma gcc optimize "Os"
#include <stdio.h>

short p, i, j;
int ans;
long long int N;

signed main(){
    while(~scanf("%lld", &N)){
        if(N == 1){
            printf("1\n");
            continue;
        }
        if(N > 600000000){
            printf("%lld\n", N - 1);
            continue;
        }
        ans = N;
        for(i = 2; i * i <= N; i++){
            if(!(N % i)){
                ans = ans / i * (i - 1);
                while(!(N % i)) N /= i;
            }
        }
        if(N > 1) ans = ans / N * (N - 1);
        printf("%d\n", ans);
    }
    return 0;
}
