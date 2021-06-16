#include <iostream>
#include <utility>
#include <math.h>
#include <algorithm>
#include <vector>
#define int long long int
#define pd pair<double,double>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
using namespace std;

int N;
double x, y, d;
const double eps = 2e-8;

pd getRange(double x, double y){
    if(y * y - d * d > eps) return {71.0, 22.0};
    return {x - sqrt(d * d - y * y), x + sqrt(d * d - y * y)};
}

vector<pd> ranges;

bool cmp(pd a, pd b){
    return a.S < b.S - eps;
}

signed main(){
    ericxiao;
    cin >> N >> d;
    pd rg;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        rg = getRange(x, y);
        if(rg.F - rg.S > eps){
            cout << -1 << endl;
            return 0;
        }
        //cout << "Range: " << getRange(x, y).F << ", " << getRange(x, y).S << endl;
        ranges.push_back(getRange(x, y));
    }
    sort(ranges.begin(), ranges.end(), cmp);
    int puts = 1;
    double lastput = ranges[0].S;
    for(int i = 1; i < N; i++){
        if(lastput < ranges[i].F - eps){
            puts++;
            lastput = ranges[i].S;
        }
    }
    cout << puts << endl;
}
