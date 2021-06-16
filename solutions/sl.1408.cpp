#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int N, l, r, c, has[maxN], before[maxN];



struct Job{
    int l, r, c;
    Job(){}
    Job(int l, int r, int c): l(l), r(r), c(c){}
    bool operator<(const Job &j) const {
        return r < j.r;
    }
};

struct BIT{
	int bit[maxN];
	BIT(){
		fill(bit, bit + maxN, 0);
	}
	inline void modify(int p, int x){
		for(; p < maxN; p += (p & -p)) bit[p] += x;
	}
	inline int query(int p){
		int r = 0;
		for(; p > 0; p -= (p & -p)) r += bit[p];
		return r;
	}
} bit;

vector<Job> steve; //Steve Jobs
vector<int> indices;

int main(){
	ericxiao;
    while(cin >> N){
        if(!N) return 0;
		vector<Job>().swap(steve);
		bit = BIT();
		for(int i = 0; i < N; i++){
			cin >> l >> r >> c;
			l++, r++;
			steve.emplace_back(l, r, c);
		}
		sort(steve.begin(), steve.end());
		for(int i = 1; i < maxN; i++){
			has[i] = 0;
			before[i] = i - 1;
		}
		for(Job job : steve){
			int cnt = job.c - bit.query(job.r) + bit.query(job.l), id = job.r;
			vector<int>().swap(indices);
			while(cnt > 0){
				//cout << "id = " << id << endl;
				if(!has[id]){
					//cout << "Placing at " << id << endl;
					has[id] = 1;
					bit.modify(id, 1);
					cnt--;
					indices.push_back(id);
				}
				id = before[id];
			}
			reverse(indices.begin(), indices.end());
			for(int i : indices){
				before[i + 1] = before[i];
			}
			//for(int i = 1; i <= 12; i++) cout << has[i] << " ";
			//cout << endl;
			//for(int i = 1; i <= 12; i++) cout << before[i] << " ";
			//cout << endl;
		}
		cout << bit.query(maxN - 1) << '\n';
    }
}

