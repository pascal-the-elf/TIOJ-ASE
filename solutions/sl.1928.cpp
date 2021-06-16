#include <iostream>
#include <utility>
#include <math.h>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 805, INF = 1e18;
int N, m; //xiao 800 <3
double dp[maxN][maxN];
int from[maxN][maxN];

struct Point{
    int F, S, id;
    Point(){}
    Point(int F, int S, int id): F(F), S(S), id(id){}
};

Point points[maxN], ch[maxN];

inline double dist(int i, int j){
    return sqrt((points[i].F - points[j].F) * (points[i].F - points[j].F) * 1.0 + (points[i].S - points[j].S) * (points[i].S - points[j].S) * 1.0);
}

inline Point operator-(Point a, Point b){
    return Point(a.F - b.F, a.S - b.S, -1);
}

inline int operator*(Point a, Point b){
    return a.F * b.S - a.S * b.F;
}

void getAns(int i, int j){
    if(j <= i + 1) return;
    if(i + 1 < from[i][j]){
        cout << points[i].id << " " << points[from[i][j]].id << endl;
        getAns(i, from[i][j]);
    }
    if(from[i][j] < j - 1){
        cout << points[j].id << " " << points[from[i][j]].id << endl;
        getAns(from[i][j], j);
    }
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> points[i].F >> points[i].S;
        points[i].id = i;
    }
    for(int i = 0; i < N; i++){
        while(m > 1 && (ch[m - 1] - ch[m - 2]) * (points[i] - ch[m - 1]) <= 0) m--;
        ch[m++] = points[i];
    }
    int sz = m;
    for(int i = N - 2; i >= 0; i--){
        while(m > sz && (ch[m - 1] - ch[m - 2]) * (points[i] - ch[m - 1]) <= 0) m--;
        ch[m++] = points[i];
    }
    swap(ch, points);
    for(int i = N - 1; i >= 0; i--){
        for(int j = i + 1; j < N; j++){
            if(i + 1 == j){
                dp[i][j] = dist(i, j);
            } else {
                dp[i][j] = INF;
                for(int k = i + 1; k < j; k++){
                    if(dp[i][k] + dp[k][j] + dist(i, j) < dp[i][j]){
                        dp[i][j] = dp[i][k] + dp[k][j] + dist(i, j);
                        from[i][j] = k;
                    }
                }
            }
        }
    }
    getAns(0, N - 1);
}
