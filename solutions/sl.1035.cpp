#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MOD = 998244353, root = 3, maxN = 5e4 + 10;

int maxLog, afrq[1 << 17], bfrq[1 << 17], match[1 << 17];
bool has[30];
char a[maxN], b[maxN];
inline char readchar() {
    const int B = 1<<17;
    static char buf[B], *p = buf, *q = buf;
    if(p==q && (q=(p=buf)+fread_unlocked(buf,1,B,stdin)) == buf) return EOF;
    return *p++;
}
inline char* reads(char *s) {
    while(isspace(*s = readchar()));
    s++;
    while(isgraph(*s = readchar())){
        has[*s++ - 'a'] = true;
    }
    return s;
}
int modpow(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = modpow(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

inline int modinv(int x){
    return modpow(x, MOD - 2);
}

inline void bitInversePermutation(int f[], int n){
    for(int i = 0, j = 0; i < n; i++) {
        if(i < j) swap(f[i], f[j]);
        for(int k = n>>1; (j^=k) < k; k>>=1);
    }
}

inline void ntt(int f[], int n, bool inv = false){
    bitInversePermutation(f, n);
    int omega, tw;
    for(int g = 2; g <= n; g *= 2){
        omega = modpow(root, (MOD - 1) / g);
        if(inv) omega = modinv(omega);
        for(int i = 0; i < n; i += g){
            tw = 1;
            for(int j = i; j < i + g/2; j++){
                int s = f[j], t = f[j + g/2] * tw % MOD;
                f[j] = (s + t >= MOD ? s + t - MOD : s + t);
                f[j + g/2] = (s - t < 0 ? s - t + MOD : s - t);
                tw = tw * omega % MOD;
            }
        }
    }
    if(inv){
        int iN = modinv(n);
        for(int i = 0; i < n; i++) f[i] = f[i] * iN % MOD;
    }
}


signed main(){
    int al = reads(a) - a, bl = reads(b) - b;
    //cout << al << ' ' << bl << '\n';
    //cout << a << ", " << b << endl;
    reverse(a, a + al);
    maxLog = 0;

    for(;(1<<maxLog) <= (al + bl); maxLog++);
    int n = (1 << maxLog);
    //cout << "n = " << n << endl;
    int me = -1;
    for(int c = 0; c < 26; c++){
        if(!has[c]) continue;
        for(int i = 0; i < n; i++) afrq[i] = (i < al) && (a[i] == (c + 'a'));
        for(int i = 0; i < n; i++) bfrq[i] = (i < bl) && (b[i] == (c + 'a'));
        ntt(afrq, n);
        ntt(bfrq, n);
        for(int i = 0; i < n; ++i){
            afrq[i] = afrq[i] * bfrq[i] % MOD;
        }
        ntt(afrq, n, true);
        for(int i = 0; i < n; ++i){
            match[i] += afrq[i];
            if(match[i] > me) me = match[i];
        }
    }
    cout << me << '\n';

}
