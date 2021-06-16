#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


vector<int> SA, nextrk, rk, lcp;
int gap, N;

bool cmp(int i, int j){
    if(rk[i] != rk[j]) return rk[i] < rk[j];

    i += gap;
    j += gap;

    if(i < N && j < N) return rk[i] < rk[j];
    else return i > j;
}

void getSA(string s){
    SA.resize(N);
    nextrk.resize(N);
    rk.resize(N);

    nextrk[0] = 0;

    for(int i = 0; i < N; i++){
        SA[i] = i;
        rk[i] = s[i] - 'a';
    }

    for(gap = 1;; gap *= 2){
        sort(SA.begin(), SA.end(), cmp);
        for(int i = 1; i < N; i++) nextrk[i] = nextrk[i-1] + cmp(SA[i - 1], SA[i]);
        for(int i = 0; i < N; i++) rk[SA[i]] = nextrk[i];
        if(nextrk[N - 1] == N - 1) break;
    }
}

void getlcp(string s){
    lcp.resize(N);
    int k = 0;
    vector<int> SAinv;
    SAinv.resize(N);
    for(int i = 0; i < N; i++){
        SAinv[SA[i]] = i;
    }

    for(int i = 0; i < N; i++){
        if(!rk[i]){
            k = 0;
            continue;
        }
        int j = SA[rk[i] - 1];
        while(i + k < N && j + k < N && s[i + k] == s[j + k]) k++;
        lcp[SAinv[i]] = k;
        if(k) k--;
    }
}

int T, m, n;
string a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> a >> b){
        string s = a + '$' + b;
        N = s.length();
        getSA(s);
        getlcp(s);
        int ans = 0, maxInd;
        for(int i = 2; i < N; i++){
            if((SA[i] - m) * (SA[i - 1] - m) < 0){
                if(ans < lcp[i]){
                    ans = lcp[i];
                    maxInd = SA[i];
                }
            }
        }

    }
}
