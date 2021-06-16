#include <cstdio>
#include <map>
#define F first
#define S second
using namespace std;

int x;
map<int, int> mp;

int main(){
    while(scanf("%d", &x)){
        if(!x) return 0;
        if(x == -1){
            if(!mp.size()) continue;
            printf("%d ", mp.begin()->F);
            mp.begin()->S--;
            if(!mp.begin()->S) mp.erase(mp.begin());
        } else if(x == -2){
            if(!mp.size()) continue;
            printf("%d ", mp.rbegin()->F);
            mp.rbegin()->S--;
            if(!mp.rbegin()->S) mp.erase(--mp.end());
        } else {
            mp[x]++;
        }
    }
}

