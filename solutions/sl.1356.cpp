#include <iostream>
using namespace std;

int N, cnt = 0;

void solve(int d, int f, int t){
    if(!d) return;
    if(f == 1 && t == 3){
        solve(d - 1, 1, 3);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 1, 2);
        solve(d - 1, 3, 1);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 2, 3);
        solve(d - 1, 1, 3);
    } else if(f == 1 && t == 2){
        solve(d - 1, 1, 3);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 1, 2);
        solve(d - 1, 3, 2);
    } else if(f == 2 && t == 3){
        solve(d - 1, 2, 1);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 2, 3);
        solve(d - 1, 1, 3);
    } else if(f == 2 && t == 1){
        solve(d - 1, 2, 3);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 2, 1);
        solve(d - 1, 3, 1);
    } else if(f == 3 && t == 1){
        solve(d - 1, 3, 1);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 3, 2);
        solve(d - 1, 1, 3);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 2, 1);
        solve(d - 1, 3, 1);
    } else if(f == 3 && t == 2){
        solve(d - 1, 3, 1);
        printf("#%d : move the dish from #%d to #%d\n", ++cnt, 3, 2);
        solve(d - 1, 1, 2);
    }
}

int main(){
    cin >> N;
    solve(N, 1, 3);
}
