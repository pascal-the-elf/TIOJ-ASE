#include <set>
#include <iostream>
int N, M, a, b, maxL = 0;
using namespace std;

set<long long int> s;

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        a--;
        if(s.count(a)) s.erase(a);
        else s.insert(a);
        if(s.count(b)) s.erase(b);
        else s.insert(b);
        maxL = max(maxL, (int)(s.size() + 1)/ 2);
    }
    printf("%d\n", maxL);
}
