#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//By S
string s;
int ranks[100000 + 5], newRanks[100000 + 5], sa[100000 + 5];
struct Cmp{
    int *ranks, n, N; //n is the current length.
    bool operator()(int i, int j){
        if(ranks[i] != ranks[j]) return ranks[i] < ranks[j];
        int a = (i + n < N) ? ranks[i + n] : -1;
        int b = (j + n < N) ? ranks[j + n] : -1;
        return a < b;
    }
};

int main(){
    getline(cin, s);
    int l = s.length();
    if(!l) return 0;
    for(int i = 0; i < l; i++){
        ranks[i] = s[i]; //rank using ASCII encoding, equiv to ranking m = 1
        sa[i] = i; //whatever, it's gonna get rewritten anyway lol
    }
    for(int m = 1; m <= l; m *= 2){
        Cmp cmp;
        cmp.ranks = ranks;
        cmp.n = m;
        cmp.N = l;
        sort(sa, sa + l, cmp); //sort SA according to rank
        //now update rank
        int r = 0;
        newRanks[sa[0]] = r; //rank first = 0
        for(int i = 1; i < l; i++){
            if(cmp(sa[i-1], sa[i])) r++; //we know that sa[i-1] <= sa[i], and if it's <, then it's different, and
                                        //needs to be updated. Else r will stay the same
            newRanks[sa[i]] = r; //set the new rank
        }
        swap(ranks, newRanks);
        if(r == l) break;
    }
    for(int i = 0; i < l; i++){
        cout << sa[i] << endl;
    }

}
