#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int lim = 999571 + 226;

int seq[lim];

signed main(){
    ericxiao;
    seq[1] = 1;
    seq[2] = 2;
    seq[3] = 2;
    int cnt = 4;
    for(int i = 3; cnt < lim; i++){
        for(int j = 0; j < seq[i] && cnt < lim; j++){
            seq[cnt++] = i;
        }
    }
    vector<int> lims;
    lims.push_back(1);
    cnt = 1;
    for(int i = 2; i < lim; i++){
        lims.push_back(cnt + seq[i]);
        cnt += seq[i];
    }
    int n;
    while(cin >> n){
        if(!n) return 0;
        cout << lower_bound(lims.begin(), lims.end(), n) - lims.begin() + 1 << endl;
    }
}
