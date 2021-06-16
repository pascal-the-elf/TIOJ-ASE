#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked

using namespace std;

const int maxN = 5e5 + 10;

int N, T, vals[maxN], lis[maxN];

void read(int &x)
{
    int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


struct BIT{
    int arr[maxN], N;
    BIT(){}
    BIT(int n): N(n){
        fill(arr, arr + N + 1, 0);
    }
    inline void add(int p, int x){
        for(;p <= N; p += (p & -p)) arr[p] += x;
    }
    inline int query(int p){
        int r = 0;
        for(;p > 0; p -= (p & -p)) r += arr[p];
        return r;
    }
} bit;

int main(){
    int c = 0;
    scanf("%d", &N);
    while(N){
        if(!N) return 0;
        bit = BIT(N + 1);
        for(int i = 0; i < N; i++){
            scanf("%d", vals + i);
            lis[i] = vals[i];
        }
        sort(lis, lis + N);
        int sz = unique(lis, lis + N) - lis;
        for(int i = 0; i < N; i++) vals[i] = upper_bound(lis, lis + sz, vals[i]) - lis;
        long long int ans = 0;
        for(int i = 0; i < N; i++){
            ans += bit.query(N + 1) - bit.query(vals[i]);
            bit.add(vals[i], 1);
        }
        printf("Case #%d: %lld\n", ++c, ans);
        scanf("%d", &N);
    }
}
