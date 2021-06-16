#include <iostream>
using namespace std;

int T, n, k;

int solve(int n, int k){
    if(n == 1) return 0;
    return (solve(n - 1, k) + k) % n;
}

int main(){
    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        scanf("%d%d", &n, &k);
        printf("Case %d: %d\n", c, solve(n, k) + 1);
    }
}
