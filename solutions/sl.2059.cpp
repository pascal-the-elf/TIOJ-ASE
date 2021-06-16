//#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#include <iostream>
#include <utility>
#include <math.h>
#include <iomanip>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 500005;
const double eps = 1;
int n, m, a, b, opt[maxn];
int dp[maxn], pa[maxn], pb[maxn], pab[maxn];

pii solve(int &D, int &C){
    for(int i = 1; i <= n; i++){
        int &d = dp[i];
        int &o = opt[i];

        d = dp[i - 1];
        o = 0;

        if(d < dp[i - 1] + pa[i] - D){
            d = dp[i - 1] + pa[i] - D;
            o = 1;
        }

        if(d < dp[i - 1] + pb[i] - C){
            d = dp[i - 1] + pb[i] - C;
            o = 2;
        }

        if(d < dp[i - 1] + pab[i] - C - D){
            d = dp[i - 1] + pab[i] - C - D;
            o = 3;
        }
    }

    pii ret = pii(0, 0);

    for(int i = 1; i <= n; i++){
        if(opt[i] > 1)
            ret.second++;

        if(opt[i] & 1)
            ret.first++;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    if(m == 1){
        cin >> a;
        b = 0;
        for(int i = 1; i <= n; i++){
            cin >> pa[i];
            pa[i] /= 100;
        }
        for(int i = 1; i <= n; i++){
            pb[i] = 0;
        }
    }
    else if(m == 2){
        cin >> a >> b;
        for(int i = 1; i <= n; i++){
            cin >> pa[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> pb[i];
        }
    }
    for(int i = 1; i <= n; i++)
        pab[i] = (100*pa[i] + 100*pb[i] - pa[i] * pb[i]) / 100;

    int lo = 0, hi = 100000000, mid, lo2 = 0, hi2 = 1000000, mid2, r1, r2;

    mid = (lo + hi) / 2;

    pii R1, R2;
    do{
        mid = (lo + hi) / 2;
        lo2 = 0, hi2 = 1000000, mid2;
        do{
            mid2 = (lo2 + hi2) / 2;
            R2 = solve(mid, mid2);
            if(R2.second > b)
                lo2 = mid2;
            else
                hi2 = mid2;
        } while(fabs(R2.second - b) > eps);
        R1 = solve(mid, hi2);
        if(R1.first > a)
            lo = mid;
        else
            hi = mid;
    } while(fabs(R1.first - a) > eps);


    for(int it2 = 0; it2 < 50; it2++){
        mid = (lo + hi) / 2;

        lo2 = 0, hi2 = 1000000000, mid2;

        for(int it = 0; it < 50; it++){
            mid2 = (lo2 + hi2) / 2;

            if(solve(mid, mid2).second > b)
                lo2 = mid2;
            else
                hi2 = mid2;
        }

        if(solve(mid, hi2).first > a)
            lo = mid;
        else
            hi = mid;
    }
    solve(hi, hi2);
    cout << fixed << setprecision(0) << (dp[n] + hi2 * b + hi * a) * pow(100, m - 1) << endl;
    return 0;
}
