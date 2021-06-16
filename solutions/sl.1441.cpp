#include <iostream>
#include <deque>
using namespace std;

const int maxN = 1e6 + 226;

int x, N;

deque<int> ans;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(!ans.size()){
            ans.push_back(x);
            continue;
        }
        if(ans.size() % 2){
            if(ans.back() <= x)
                ans.pop_back();
            ans.push_back(x);
        } else {
            if(ans.back() >= x)
                ans.pop_back();
            ans.push_back(x);
        }
    }
    cout << (ans.size() % 2 ? ans.size() : ans.size() - 1) << endl;
}
