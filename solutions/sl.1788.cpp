#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 5e5 + 10, INF = 1e9;

int arr[maxN], sz;

string tgt, cur;

struct Opt{
    int a, b, id;
    Opt(){}
    Opt(int a, int b, int id): a(a), b(b), id(id){}
    bool operator<(const Opt o) const {
        return (b - a) < (o.b - o.a);
    }
};

struct RMQ{
    int seg[maxN * 4], tag[maxN * 4];
    int n;
    inline void pull(int id){
        seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
    }
    inline void push(int id, int l, int r){
        seg[id] += tag[id];
        if(l + 1 < r){
            tag[2 * id + 1] += tag[id];
            tag[2 * id + 2] += tag[id];
        }
        tag[id] = 0;
    }
    void build(int id, int l, int r){
        tag[id] = 0;
        if(l + 1 == r){
            seg[id] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
        pull(id);
    }
    void mdf(int id, int ql, int qr, int l, int r, int val){
        //cout << "MDF " << id << " " << ql << " " << qr << " " << l << " " << r << " " << val << endl;
        push(id, l, r);
        if(l >= qr || ql >= r) return;
        if(ql <= l && r <= qr){
            tag[id] += val;
            push(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        mdf(2 * id + 1, ql, qr, l, m, val);
        mdf(2 * id + 2, ql, qr, m, r, val);
        pull(id);
    }
    int qry(int id, int ql, int qr, int l, int r){
        push(id, l, r);
        if(l >= qr || ql >= r) return INF;
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return min(qry(2 * id + 1, ql, qr, l, m), qry(2 * id + 2, ql, qr, m, r));
    }
    void modify(int l, int r, int val){
        mdf(0, l, r, 0, n, val);
    }
    int query(int l, int r){
        return qry(0, l, r, 0, n);
    }
    RMQ(int n): n(n){
        build(0, 0, n);
    }
};

int T, a, b, ans;

signed main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> tgt;
        cur = tgt;
        vector<Opt> opts;
        ans = sz = 0;
        for(int i = 0; i < tgt.length(); i++){
            if(tgt[i] == '?'){
                cur[i] = '(';
                cin >> a >> b;
                ans += a;
                opts.emplace_back(a, b, i);
            }
        }
        bool can = true;
        for(int i = 0; i < cur.length(); i++){
            if(cur[i] == '(') sz++;
            else {
                if(!sz){
                    can = false;
                    break;
                } else {
                    sz--;
                }
            }
            arr[i] = sz;
            //cout << arr[i] << " ";
        }
        //cout << endl;
        sort(opts.begin(), opts.end());
        RMQ rmq = RMQ(tgt.length());
        //cout << rmq.query(0, tgt.length()) << ", " << rmq.query(tgt.length() - 1, tgt.length()) << endl;
        if(!can || rmq.query(tgt.length() - 1, tgt.length()) % 2){
            cout << "QAQ\n";
            continue;
        }
        for(auto o : opts){
            //cout << "o: " << o.a << ", " << o.b << ", " << o.id << endl;
            //cout << "MIN: " <<rmq.query(o.id, tgt.length()) << endl;
            if(rmq.query(o.id, tgt.length()) >= 2){
                //cout << "YE" << endl;
                cur[o.id] = ')';
                ans += (o.b - o.a);
                rmq.modify(o.id, tgt.length(), -2);
            }
        }
        //cout << cur << endl;
        if(rmq.query(tgt.length() - 1, tgt.length())) cout << "-1" << endl;
        else cout << ans << endl;
    }
}
