#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int LIM = (1LL<<35);

vector<int> fibs;

/*
Fucking negative numbers and zero...
*/

signed main(){
    ericxiao;
    fibs.push_back(1);
    fibs.push_back(2);
    while(*fibs.rbegin() <= LIM){
        fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
    }
    reverse(fibs.begin(), fibs.end());
    int N, x;
    cin >> N;
    while(N--){
        int c = 0;
        cin >> x;
        if(!x){
            cout << 0 << endl;
            continue;
        }
        if(x < 0){
            cout << "iyada~" << endl;
            continue;
        }
        for(int t : fibs){
            if(t <= x){
                c++;
                x -= t;
            }
        }
        cout << c << endl;
    }
}
