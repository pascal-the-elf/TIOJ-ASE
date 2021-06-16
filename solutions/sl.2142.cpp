#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int N, pos[maxN], x, cpos;
vector<int> ans;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        pos[x] = i;
    }
    for(int i = 1; i <= N; i++){
        i++;
        while(i <= N && pos[i] >= pos[i - 1]) i++;
        ans.emplace_back(i);
        i--;
    }
    cout << ans.size() - 1 << endl;
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] - ans[i - 1];
        for(int j = ans[i - 1]; j < ans[i]; j++) cout << " " << j;
        cout << endl;
    }
}
