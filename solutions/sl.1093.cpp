//#pragma optimize ("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <math.h>
#include <random>
#include <iomanip>
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
using namespace std;

const int maxN = 2e3 + 10;

pdd points[maxN], ch[maxN];
double coords[1005][2];

int n, m, x, y;
double cX, cY, rad, newX, newY, newR;


inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=readchar();
        if(c=='-')
        {
            neg = true;
            c=readchar();
        }
        for(;(c>47 && c<58);c=readchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

pdd getCirc(pdd a, pdd b, pdd c){
    double ax = a.F, ay = a.S, bx = b.F, by = b.S, cx = c.F, cy = c.S;
    double d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    double ux = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d;
    double uy = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d;
    return {ux, uy};
}

int main(){
    //cout << fixed << setprecision(3) << endl;
    srand(time(NULL));
    fastscan(m);
    fastscan(n);
    while(true){
        if(!m && !n) return 0;
        for(int i = 0; i <= m; i++){
            coords[i][0] = maxN;
            coords[i][1] = -1;
        }
        for(int i = 0; i < n; i++){
            fastscan(x);
            fastscan(y);
            coords[(int)x][0] = min(coords[(int)(x)][0], (double)y);
            coords[(int)x][1] = max(coords[(int)(x)][1], (double)y);
        }

        //continue;
        int t = 0;
        for(int i = 0; i <= m; i++){
            if(coords[i][1] != -1){
                points[t++] = {i, coords[i][1]};
            }
            if(coords[i][0] != coords[i][1] && coords[i][0] != maxN){
                points[t++] = {i, coords[i][0]};
            }
        }
        n = t;
        m = 0;

        for(int i = 0; i < n; i++){
            while(m > 1 && (ch[m - 1].S - ch[m - 2].S) * (points[i].F - ch[m - 1].F) >= (points[i].S - ch[m - 1].S) *  (ch[m - 1].F - ch[m - 2].F) ){
                m--;
            }
            ch[m] = points[i];
            m++;
        }
        int sz = m;
        m = 0;
        for(int i = n - 1; i >= 0; i--){
            while(m >= 1 && (ch[sz + m - 1].S - ch[sz + m - 2].S) * (points[i].F - ch[sz + m - 1].F) >= (points[i].S - ch[sz + m - 1].S) *  (ch[sz + m - 1].F - ch[sz + m - 2].F) ){
                m--;
            }
            ch[m + sz] = points[i];
            m++;
        }
        sz += m;
        n = sz;
        for(int i = 0; i < n; i++) points[i] = ch[i];
        //cout << "sz = " << sz << endl;
        //for(int i = 0; i < sz; i++) cout << points[i].F << ", " << points[i].S << endl;
        //cout << endl;
        //shuffle(points, points + n, default_random_engine(time(NULL)));
        //for(int i = 0; i < sz; i++) cout << points[i].F << ", " << points[i].S << endl;
        //cout << endl;
        cX = (points[0].F + points[1].F) / 2;
        cY = (points[0].S + points[1].S) / 2;
        //cout << "Choosing (" << cX << ", " << cY << ")" << endl;
        rad = hypot((cX - points[0].F), (cY - points[0].S));
        //cout << "Starting rad = " << rad << endl;
        for(int i = 2; i < n; i++){ //try to add ith point
            //cout << "Adding points[" << i << "]" << endl;
            if(hypot((cX - points[i].F), (cY - points[i].S)) <= rad) continue;
            //must go through points[i] and enclose points[0] ~ points[i - 1]
            newX = (points[0].F + points[i].F) / 2;
            newY = (points[0].S + points[i].S) / 2;
            newR = hypot((newX - points[0].F), (newY - points[0].S));
            for(int j = 1; j < i; j++){
                if(hypot((newX - points[j].F), (newY - points[j].S)) <= newR) continue;
                //must go through points[i] and points[j] and enclose points[0] ~ points[j - 1]
                double bX, bY, bR;
                bX = (points[i].F + points[j].F) / 2;
                bY = (points[i].S + points[j].S) / 2;
                bR = hypot((bX - points[i].F), (bY - points[i].S));
                pdd p;
                for(int k = 2; k < j; k++){
                    if(hypot(points[k].F - bX, points[k].S - bY) <= bR) continue;
                    p = getCirc(points[i], points[j], points[k]);
                    bX = p.F;
                    bY = p.S;
                    bR = hypot(bX - points[i].F, bY - points[i].S);
                }
                newX = bX;
                newY = bY;
                newR = bR;
            }
            cX = newX;
            cY = newY;
            rad = newR;
        }
        printf("%.3lf\n", rad);
        //cout << rad << endl;
        fastscan(m);
        fastscan(n);
    }
}
