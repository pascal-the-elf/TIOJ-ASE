#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked

using namespace std;

const int maxN = 2e7 + 10;

int N, arr[maxN], sum = 0, wsum = 0;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

signed main(){
    ericxiao;
    scanint(N);
    for(int i = 0; i < N; i++){
        scanint(arr[i]);
        sum += arr[i];
        wsum += arr[i] * i;
    }
    for(int x = 0; x < N; x++){
        if(!(wsum % sum)){
            cout << x << " " << wsum / sum << endl;
            return 0;
        } else {
            wsum += (arr[x] - arr[N - 1- x]) * (N - 1 - 2 * x);
        }
    }
}
