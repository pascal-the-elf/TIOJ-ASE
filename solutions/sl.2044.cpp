#include <cstdio>
#define int long long int
using namespace std;

const int B = 271, MOD = 2147483647;

int T, N, M, x, ph1, ph2, h1, h2;
bool can;

signed main(){
    scanf("%lld", &T);
    while(T--){
        scanf("%lld%lld", &N, &M);
        can = true;
        ph1 = ph2 = 0;
        for(int i = 0; i < M; i++){
            scanf("%lld", &x);
            if(i < M - 1) ph1 = (ph1 * B % MOD + x) % MOD;
            if(i) ph2 = (ph2 * B % MOD + x) % MOD;
        }
        for(int i = 1; i < N; i++){
            h1 = h2 = 0;
            for(int j = 0; j < M; j++){
                scanf("%lld", &x);
                if(j < M - 1) h1 = (h1 * B % MOD + x) % MOD;
                if(j) h2 = (h2 * B % MOD + x) % MOD;
            }
            can &= (ph1 == h2);
            ph1 = h1;
            ph2 = h2;
        }
        if(can){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
