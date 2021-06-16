#include <queue>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, k, ans = 0, a, b;
vector<int> v;
deque<int> unmerged, merged;
int main(){
    ericxiao;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int u : v) unmerged.push_back(u);
    int a, b, currentChoice = 0, minCost;
    for(int i = 0; i < n - 1; i++){
        minCost = 1e8;
        if(unmerged.size() > 1){
            a = unmerged.front();
            unmerged.pop_front();
            b = unmerged.front();
            unmerged.pop_front();
            if(minCost > (a + b)){
                minCost = a + b;
                currentChoice = 0;
            }
            unmerged.push_front(b);
            unmerged.push_front(a);
        }
        if(unmerged.size() > 0 && merged.size() > 0){
            a = unmerged.front();
            unmerged.pop_front();
            b = merged.front();
            merged.pop_front();
            if(minCost > (a + b)){
                minCost = a + b;
                currentChoice = 1;
            }
            merged.push_front(b);
            unmerged.push_front(a);
        }
        if(merged.size() > 1){
            a = merged.front();
            merged.pop_front();
            b = merged.front();
            merged.pop_front();
            if(minCost > (a + b)){
                minCost = a + b;
                currentChoice = 2;
            }
            merged.push_front(b);
            merged.push_front(a);
        }
        if(currentChoice == 0){
            unmerged.pop_front();
            unmerged.pop_front();
        } else if(currentChoice == 1){
            merged.pop_front();
            unmerged.pop_front();
        } else {
            merged.pop_front();
            merged.pop_front();
        }
        merged.push_back(minCost);
        ans += minCost;
    }
    cout << ans << '\n';
}
